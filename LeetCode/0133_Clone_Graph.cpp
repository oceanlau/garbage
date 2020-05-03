/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        stack<Node*> st;
        unordered_map<int, Node*> visited;
        if (!node) {
            return NULL;
        }
        Node* root = new Node(node->val);
        st.push(node);
        visited[root->val] = root;
        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();
            for (Node* n : cur->neighbors) {
                if (!visited.count(n->val)) {
                    visited[n->val] = new Node(n->val);
                    st.push(n);
                }
                visited[cur->val]->neighbors.push_back(visited[n->val]);
            }
        }
        return root;
    }
};

//95% 96%
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return node;
        }
        //cant use set, unless unable to know when copy neighbor
        //unordered_set<Node*> visited;
        unordered_map<Node*, Node*> visited;
        queue<Node*> to_visit;
        Node* res = new Node(node->val, vector<Node*> {});
        to_visit.push(node);
        visited[node] = res;
        while (to_visit.size() != 0) {
            Node* cur = to_visit.front();
            to_visit.pop();
            for (const auto neighbor : cur->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    to_visit.push(neighbor);
                    Node* new_node = new Node(neighbor->val, vector<Node*> {});
                    visited[neighbor] = new_node;
                }
                visited[cur]->neighbors.push_back(visited[neighbor]);
            }
        }
        return res;
    }
};
