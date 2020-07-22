class TrendingStock {
private:
    unordered_map<string, pair<int, list<string>::iterator>> stock_freq;
    unordered_map<int, pair<list<int>::iterator, list<string>>> freq_stocks;
    list<int> freqs;
public:

	void processStock(string stock) {
        if (stock_freq.count(stock)) {
            int freq = stock_freq[stock].first;
            list<string>::iterator stock_it = stock_freq[stock].second;
            list<int>::iterator freq_it = freq_stocks[freq].first;
            freq_it ++;
            freq_stocks[freq].second.erase(stock_it);
            if (*freq_it == freq + 1) {
                freq_stocks[freq + 1].second.push_front(stock);
            } else {
                auto new_freq_it = freqs.insert(freq_it, freq + 1);
                freq_stocks[freq + 1] = make_pair(new_freq_it, list<string> {stock});
            }
            stock_freq[stock] = make_pair(freq + 1, freq_stocks[freq + 1].second.begin());
        } else {}
	}

	string getTrendingStock() {
	}

}
