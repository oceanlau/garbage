//trie+sort, 16% 14%, heavy string concat
struct TrieNode {
    int time = 0;
    //Put the full sentence here to avoid string concats
    //string sentence = "";
    vector<TrieNode*> children = vector<TrieNode*> (27, NULL);
};

class AutocompleteSystem {
private:
    string _cur = "";
    TrieNode* _root = new TrieNode();
    TrieNode* _curNode = NULL;
    int _curDepth = 0;
    void _buildTrie(string sentence, int time) {
        TrieNode* curNode = _root;
        for (int i = 0; i < sentence.length(); i++) {
            int char_nth = sentence[i] - 'a';
            // for the ' ' space
            if (char_nth < 0 || char_nth > 25) {
                char_nth = 26;
            }
            if (curNode->children[char_nth] == NULL) {
                curNode->children[char_nth] = new TrieNode();
            }
            curNode = curNode->children[char_nth];
        }
        curNode->time = time;
    }
    void _dfs(TrieNode* node, vector<pair<string, int>>& sentences, string prefix) {
        if (node->time > 0) {
            sentences.push_back(pair<string, int> {prefix, node->time});
        }
        for (int i = 0; i < 27; i++) {
            if (node->children[i] != NULL) {
                string tmp = prefix;
                if (i == 26) {
                    tmp += ' ';
                } else {
                    tmp += (char) ('a' + i);
                }
                _dfs(node->children[i], sentences, tmp);
            }
        }
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        //iterate sentences and times, call _buildTrie
        for (int i = 0; i < sentences.size(); i++) {
            _buildTrie(sentences[i], times[i]);
        }
        _curNode = _root;
    }
    
    vector<string> input(char c) {
        //if normal char, if _curDepth != _cur.length() (not mathcing), concat into _cur
        //                else concat into _cur, look at the _curNode (if no this child, return empty), _curDepth++, do dfs, sort, return
        if (c != '#') {
            _cur += c;
            
            int char_nth = c - 'a';
            // for the ' ' space
            if (char_nth < 0 || char_nth > 25) {
                char_nth = 26;
            }
            
            // just add 1 by _cur += c
            if (_curDepth == _cur.length() - 1) {
                if (_curNode->children[char_nth] != NULL) {
                    _curNode = _curNode->children[char_nth];
                    _curDepth ++;
                    vector<pair<string, int>> sentences;
                    _dfs(_curNode, sentences, "");
                    sort(sentences.begin(), sentences.end(), [](const pair<string, int>& l, const pair<string, int>& r){
                        if (l.second == r.second) {
                            return l.first < r.first;
                        } else {
                            return l.second > r.second;
                        }
                    });
                    vector<string> res;
                    for (int i = 0; i < sentences.size() && i < 3; i++) {
                        res.push_back(_cur + sentences[i].first);
                    }
                    return res;
                }
            }
        } else {
        
        
        //if sp char, if _curDepth == _cur.length(), set _curNode is sentence time++
        //            else _buildTrie(substring of _cur from _curDepth to end, 1) // maybe you don't want to do this opt in interview..
        //            clear _cur,_curDepth, _curNode=root, return empty
            
            if (_curDepth == _cur.length()) {
                _curNode->time++;
            } else {
                _buildTrie(_cur, 1);
            }
            _cur = "";
            _curDepth = 0;
            _curNode = _root;
        }
        return {};
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
