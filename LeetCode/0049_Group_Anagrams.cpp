class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < strs.size(); i++) {
            char map_key[] = "00000000000000000000000000";
            for (int j = 0; j < strs[i].length(); j++) {
                map_key[strs[i][j] - 'a'] ++;
            }
            string str_map_key(map_key);
            if (m.find(str_map_key) != m.end()) {
                m[str_map_key].push_back(i);
            } else {
                m[str_map_key] = {i};
            }
        }
        
        vector<vector<string>> v;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            vector<string> anagrams;
            for (int k = 0; k < iter->second.size(); k++) {
                anagrams.push_back(strs[iter->second[k]]);
            }
            v.push_back(anagrams);
        }
        return v;
    }
};
