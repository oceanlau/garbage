class BoundedBlockingQueue {
private:
    condition_variable enqueue_cv;
    condition_variable dequeue_cv;
    queue<int> q;
    int capacity = 0;
    mutex mu;
public:
    BoundedBlockingQueue(int capacity) {
        this->capacity = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> lock(mu);
        enqueue_cv.wait(lock, [&]{
            return q.size() < capacity;
        });
        q.push(element);
        lock.unlock();
        dequeue_cv.notify_one();
    }
    
    int dequeue() {
        unique_lock<mutex> lock(mu);
        dequeue_cv.wait(lock, [&]{
            return q.size() > 0;
        });
        int el = q.front();
        q.pop();
        lock.unlock();
        enqueue_cv.notify_one();
        return el;
    }
    
    int size() {
        unique_lock<mutex> lock(mu);
        return q.size();
    }
};
