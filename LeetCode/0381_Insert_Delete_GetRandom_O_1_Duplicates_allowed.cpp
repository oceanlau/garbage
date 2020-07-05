class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> m;
    vector<int> s;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = !m.count(val);
        s.push_back(val);
        m[val].insert(s.size() - 1);
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!m.count(val)) {
            return false;
        }
        int remove_pos = *m[val].begin();
        int substitue_val = s.back();
        // careful, the order matters!
        // these two val could be same!
        // these two pos could also be the same!
        m[val].erase(remove_pos);
        m[substitue_val].insert(remove_pos);
        m[substitue_val].erase(s.size() - 1);
        if (m[val].empty()) {
            m.erase(val);
        }
        swap(s[remove_pos], s[s.size() - 1]);
        s.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if (s.empty()) {
            return -1;
        }
        return s[rand() % s.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
