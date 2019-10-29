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
