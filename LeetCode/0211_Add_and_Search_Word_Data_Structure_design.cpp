// 36% 40%
class TrieNode {
public:
    int is_word = false;
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    ~TrieNode() {
        for (TrieNode* ptr : children) {
            delete ptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    ~WordDictionary() {
        delete root;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word.length() == 0) {
            return;
        }
        TrieNode* node = root;
        for (const char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        queue<TrieNode*> q;
        q.push(root);
        for (const char c : word) {
            int q_size = q.size();
            if (q_size == 0) {
                return false;
            } 
            while (q_size != 0) {
                TrieNode* node = q.front();
                q.pop();
                if (c == '.') {
                    for (TrieNode* child : node->children) {
                        if (child != nullptr) {
                            q.push(child);
                        }
                    }
                } else {
                    int i = c - 'a';
                    if (node->children[i] != nullptr) {
                        q.push(node->children[i]);
                    }
                }
                q_size --;
            }
        }
        while (q.size() > 0) {
            TrieNode* node = q.front();
            q.pop();
            if (node->is_word) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
