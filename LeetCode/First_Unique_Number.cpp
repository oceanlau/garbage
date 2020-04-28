class FirstUnique {
private:
    list<int> l;
    unordered_map<int, list<int>::iterator> m;
public:
    FirstUnique(vector<int>& nums) {
        for (const int n : nums) {
            add(n);
        }
    }
    
    int showFirstUnique() {
        return l.empty() ? -1 : l.front();
    }
    
    void add(int value) {
        if (!m.count(value)) {
            l.push_back(value);
            m[value] = l.end();
            m[value] --;
        } else if (m[value] != l.end()) {
            l.erase(m[value]);
            m[value] = l.end();
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
