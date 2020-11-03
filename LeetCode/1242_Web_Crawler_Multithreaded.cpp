//https://stackoverflow.com/questions/15752659/thread-pooling-in-c11

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
private:
    int num_threads = thread::hardware_concurrency();
    string hostname;
    vector<thread> pool;
    HtmlParser* parser;
    
    unordered_set<string> result;
    int num_running_worker = 0;
    queue<string> q;
    mutex mu;
    condition_variable cv;
    
    void worker() {
        while (true) {
            string url;
            {
                unique_lock<mutex> lock(mu);
                cv.wait(lock, [&]{return num_running_worker == 0 || !q.empty();});
                if (q.empty()) {
                    if (num_running_worker == 0) {
                        break;
                    }
                    continue;
                }
                url = q.front();
                q.pop();
                num_running_worker ++;
            }
            
            vector<string> crawled_urls = parser->getUrls(url);
            
            {
                unique_lock<mutex> lock(mu);
                for (const string& url : crawled_urls) {
                    if (hostname != extract_hostname(url) || result.count(url)) {
                        continue;
                    }
                    result.insert(url);
                    q.push(url);
                }
                num_running_worker --;
            }
            cv.notify_all();
        }
    }
    
    void init_thread_pool() {
        for (int i = 0; i < num_threads; i ++) {
            pool.push_back(thread([&]{worker();}));
        }
    }
    
    void join_thread_pool() {
        for (thread& t : pool) {
            t.join();
        }
    }
    
    string extract_hostname(string url) {
        stringstream ss(url);
        string hostname;
        getline(ss, hostname, '/');
        getline(ss, hostname, '/');
        getline(ss, hostname, '/');
        return hostname;
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unique_lock<mutex> lock(mu);
        parser = &htmlParser;
        result.insert(startUrl);
        q.push(startUrl);
        hostname = extract_hostname(startUrl);
        lock.unlock();
        
        init_thread_pool();
        cv.notify_one();
        join_thread_pool();
        return vector<string> (result.begin(), result.end());
    }
};
