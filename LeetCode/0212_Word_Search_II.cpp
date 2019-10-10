// Why slow?
// 53% 25% avoid word concat
class TrieNode {
public:
    bool is_word = false;
    int word_index = -1;
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    //TrieNode() {}
    ~TrieNode() {
        for (TrieNode* child : children) {
            if (child == nullptr) {
                continue;
            }
            delete child;
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int board_h = board.size();
        if (board_h == 0) {
            return res;
        }
        int board_w = board[0].size();
        TrieNode* root = _build_trie(words);
        for (int i = 0; i != board_h; i++) {
            for (int j = 0; j != board_w; j++) {
                _traverse(board, res, root, words, board_h, board_w, i, j);
            }
        }
        delete root;
        return res;
    }

private:
    TrieNode* _build_trie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i != words.size(); i++) {
            string word = words[i];
            TrieNode* node = root;
            for (const char c : word) {
                if (node->children[c-'a'] == nullptr) {
                    node->children[c-'a'] = new TrieNode();
                }
                node = node->children[c-'a'];
            }
            node->is_word = true;
            node->word_index = i;
        }
        return root;
    }
    
    void _traverse(
        vector<vector<char>>& board,
        vector<string>& res,
        TrieNode* node,
        vector<string>& words,
        int board_h,
        int board_w,
        int i,
        int j) {
        if (i < 0 || i == board_h || j < 0 || j == board_w) {
            return;
        }
        if (board[i][j] - 'a' < 0 || board[i][j] - 'a' > 26 || node->children[board[i][j] - 'a'] == nullptr) {
            return;
        }
        node = node->children[board[i][j] - 'a'];
        if (node->is_word) {
            node->is_word = false;
            res.push_back(words[node->word_index]);
        }
        char tmp = board[i][j];
        board[i][j] = '.';
        _traverse(board, res, node, words, board_h, board_w, i - 1, j);
        _traverse(board, res, node, words, board_h, board_w, i, j + 1);
        _traverse(board, res, node, words, board_h, board_w, i + 1, j);
        _traverse(board, res, node, words, board_h, board_w, i, j - 1);
        board[i][j] = tmp;
        return;
    }
};

// 36% 8%
class TrieNode {
public:
    bool is_word = false;
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    //TrieNode() {}
    ~TrieNode() {
        for (TrieNode* child : children) {
            if (child == nullptr) {
                continue;
            }
            delete child;
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int board_h = board.size();
        if (board_h == 0) {
            return res;
        }
        int board_w = board[0].size();
        TrieNode* root = _build_trie(words);
        for (int i = 0; i != board_h; i++) {
            for (int j = 0; j != board_w; j++) {
                _traverse(board, res, root, "", board_h, board_w, i, j);
            }
        }
        delete root;
        return res;
    }

private:
    TrieNode* _build_trie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            TrieNode* node = root;
            for (const char c : word) {
                if (node->children[c-'a'] == nullptr) {
                    node->children[c-'a'] = new TrieNode();
                }
                node = node->children[c-'a'];
            }
            node->is_word = true;
        }
        return root;
    }
    
    void _traverse(
        vector<vector<char>>& board,
        vector<string>& res,
        TrieNode* node,
        string word,
        int board_h,
        int board_w,
        int i,
        int j) {
        if (i < 0 || i == board_h || j < 0 || j == board_w) {
            return;
        }
        if (board[i][j] - 'a' < 0 || board[i][j] - 'a' > 26 || node->children[board[i][j] - 'a'] == nullptr) {
            return;
        }
        node = node->children[board[i][j] - 'a'];
        word += board[i][j];
        if (node->is_word) {
            node->is_word = false;
            res.push_back(word);
        }
        char tmp = board[i][j];
        board[i][j] = '.';
        _traverse(board, res, node, word, board_h, board_w, i - 1, j);
        _traverse(board, res, node, word, board_h, board_w, i, j + 1);
        _traverse(board, res, node, word, board_h, board_w, i + 1, j);
        _traverse(board, res, node, word, board_h, board_w, i, j - 1);
        board[i][j] = tmp;
        return;
    }
};
