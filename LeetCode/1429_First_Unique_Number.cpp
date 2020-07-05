class FirstUnique {
private:
    list<int> l;
    unordered_map<int, list<int>::iterator> m; 
public:
    FirstUnique(vector<int>& nums) {
        for (const int& n : nums) {
            add(n);
        }
    }
    
    int showFirstUnique() {
        if (l.empty()) {
            return -1;
        }
        return l.front();
    }
    
    void add(int value) {
        if (m.count(value)) {
            if (m[value] != l.end()) {
                l.erase(m[value]);
                m[value] = l.end();
            }
        } else {
            l.push_back(value);
            auto it = l.end();
            it --;
            m[value] = it;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
