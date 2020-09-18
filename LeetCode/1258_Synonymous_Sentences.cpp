class Solution {
private:
    vector<string> _permute(vector<string>& text_words, int start, unordered_map<string, vector<string>*>& syns) {
        vector<string> permutations;
        string cur;
        string replace_word;
        vector<string> suffixes;
        for (int i = start; i < text_words.size(); i ++) {
            if (!syns.count(text_words[i])) {
                cur += text_words[i] + ' ';
            } else {
                replace_word = text_words[i];
                suffixes = _permute(text_words, i + 1, syns);
                break;
            }
        }
        if (replace_word.length() > 0) {
            if (!suffixes.empty()) {
                for (int j = 0; j < (*syns[replace_word]).size(); j ++) {
                    for (const string& suffix : suffixes) {
                        permutations.push_back(cur + (*syns[replace_word])[j] + ' ' + suffix);
                    }
                }
            } else {
                for (int j = 0; j < (*syns[replace_word]).size(); j ++) {
                    permutations.push_back(cur + (*syns[replace_word])[j] + ' ');
                }
            }
        } else if (cur.length() > 0) {
            permutations.push_back(cur);
        }
        return permutations;
    }
    
    void _bt(string key, unordered_map<string, vector<string>>& m, unordered_set<string>& visited, unordered_map<string, vector<string>*>& syns, vector<string>* ptr) {
        visited.insert(key);
        syns[key] = ptr;
        ptr->push_back(key);
        for (int i = 0; i < m[key].size(); i ++) {
            if (!visited.count(m[key][i])) {
                _bt(m[key][i], m, visited, syns, ptr);
            }
        }
    }
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_map<string, vector<string>> m;
        for (const vector<string>& syn : synonyms) {
            m[syn[0]].push_back(syn[1]);
            m[syn[1]].push_back(syn[0]);
        }
        unordered_set<string> visited;
        vector<vector<string>> syn_store;
        int store_i = 0;
        syn_store.reserve(synonyms.size());
        unordered_map<string, vector<string>*> syns;
        for (const auto& p : m) {
            if (!visited.count(p.first)) {
                syn_store.push_back({});
                _bt(p.first, m, visited, syns, &syn_store.back());
            }
        }
        
        for (auto& v : syn_store) {
            sort(v.begin(), v.end());
        }
        stringstream ss(text);
        string word;
        vector<string> text_words;
        while (getline(ss, word, ' ')) {
            text_words.push_back(word);
        }
        vector<string> permutations = _permute(text_words, 0, syns);
        for (string& str : permutations) {
            str.pop_back();
        }
        return permutations;
    }
};
