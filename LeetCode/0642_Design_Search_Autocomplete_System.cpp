class AutocompleteSystem {
private:
    struct Node {
        struct Comp {
            bool operator()(const Node* l, const Node* r) const {
                if (l->counter == r->counter) {
                    return l->sentence < r->sentence;
                }
                return l->counter > r->counter;
            }
        };
        vector<Node*> children = vector<Node*> (27, nullptr);
        set<Node*, Comp> complete_sentences;
        string sentence = "";
        int counter = 0;
    };
    Node* _root = nullptr;
    Node* _cur = nullptr;
    string _cur_sentence = "";
    void _add(const string& sentence, const int& time) {
        Node* cur = _root;
        vector<Node*> path;
        for (const char c : sentence) {
            int child_idx = 26;
            if (isalpha(c)) {
                child_idx = c - 'a';
            }
            if (!cur->children[child_idx]) {
                cur->children[child_idx] = new Node();
            }
            path.push_back(cur->children[child_idx]);
            cur = cur->children[child_idx];
        }
        for (Node* const step : path) {
            if (step->complete_sentences.count(cur)) {
                step->complete_sentences.erase(cur);
            }
        }
        cur->sentence = sentence;
        cur->counter += time;
        for (Node* const step : path) {
            step->complete_sentences.insert(cur);
        }
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        _root = new Node();
        _cur = _root;
        for (int i = 0; i < sentences.size(); i++) {
            _add(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> result;
        if (c != '#') {
            _cur_sentence += c;
            int child_idx = 26;
            if (isalpha(c)) {
                child_idx = c - 'a';
            }
            if (!_cur->children[child_idx]) {
                _cur->children[child_idx] = new Node();
            }
            _cur = _cur->children[child_idx];
            for (auto it = _cur->complete_sentences.begin(); it != _cur->complete_sentences.end(); it ++) {
                result.push_back((*it)->sentence);
                if (result.size() == 3) {
                    break;
                }
            }
        } else {
            _add(_cur_sentence, 1);
            _cur_sentence = "";
            _cur = _root;
        }
        return result;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

struct Node {
    unordered_map<char, Node*> children;
    int cnt = 0;
    string str = "";
};

class AutocompleteSystem {
private:
    Node* _trie = new Node();
    Node* _cur = _trie;
    string _cur_str = "";
    void _add_to_trie(string sentence, int time) {
        Node* cur = _trie;
        for (const char c : sentence) {
            if (!cur->children.count(c)) {
                cur->children[c] = new Node();
            }
            cur = cur->children[c];
        }
        cur->cnt += time;
        cur->str = sentence;
    }
    vector<string> _complete(Node* root) {
        auto cmp = [](const pair<string, int>& l, const pair<string, int>& r){
            if (l.second == r.second) {
                return l.first < r.first;
            } else {
                return l.second > r.second;
            }
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> top3(cmp);
        stack<Node*> visited;
        visited.push(root);
        while (visited.size() > 0) {
            Node* cur = visited.top();
            visited.pop();
            if (cur->cnt > 0) {
                top3.push(make_pair(cur->str, cur->cnt));
                if (top3.size() > 3) {
                    top3.pop();
                }
            }
            for (const auto& kv : cur->children) {
                visited.push(kv.second);
            }
        }
        vector<string> res;
        while (top3.size() > 0) {
            res.push_back(top3.top().first);
            top3.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); i++) {
            _add_to_trie(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            _cur->str = _cur_str;
            _cur->cnt++;
            _cur = _trie;
            _cur_str = "";
            return {};
        } else {
            if (!_cur->children.count(c)) {
                _cur->children[c] = new Node();
            }
            _cur = _cur->children[c];
            _cur_str += c;
            return _complete(_cur);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

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
