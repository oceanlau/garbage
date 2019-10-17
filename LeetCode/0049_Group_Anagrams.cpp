// O(n) 90%  O(n) 31%
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map "vec" -> [str, str]
        unordered_map<string, vector<string>> map;
        // for each str, for each char, get vec
        for(int i = 0; i < strs.size(); i++) {
            string vec(26, '0');
            for (int j = 0; j < strs[i].length(); j ++) {
                // Careful here with int and char.
                vec[strs[i][j] - 'a'] = vec[strs[i][j] - 'a'] + 1;
            }
            // push into map
            if (map.find(vec) != map.end()) {
                map[vec].push_back(strs[i]);
            } else {
                map[vec] = vector<string> {strs[i]};
            }
        }
        
        vector<vector<string>> res;
        // iterate map, return
        for (auto it = map.begin(); it != map.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};

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
