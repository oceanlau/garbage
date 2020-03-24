struct Node {
    char c;
    vector<Node*> children = vector<Node*> (128, NULL);
    bool is_word = false;
};

class Trie {
private:
    Node* root = new Node();
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for (const char& c : word) {
            if (node->children[c] == NULL) {
                node->children[c] = new Node();
            }
            node = node->children[c];
        }
        node->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for (const char& c : word) {
            if (node->children[c] == NULL) {
                return false;
            }
            node = node->children[c];
        }
        return node->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for (const char& c : prefix) {
            if (node->children[c] == NULL) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
