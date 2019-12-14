/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* new_head = new Node(head->val, NULL, NULL);
        Node* cur = new_head;
        unordered_map<Node*, Node*> m;
        m[head] = new_head;
        while (head) {
            if (head->next) {
                if (m.count(head->next)) {
                    cur->next = m[head->next];
                } else {
                    cur->next = new Node(head->next->val, NULL, NULL);
                    m[head->next] = cur->next;
                }
            }
            if (head->random) {
                if (m.count(head->random)) {
                    cur->random = m[head->random];
                } else {
                    cur->random = new Node(head->random->val, NULL, NULL);
                    m[head->random] = cur->random;
                }
            }
            head = head->next;
            cur = cur->next;
        }
        return new_head;
    }
};

//93% 26%
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
private:
    void _dfs(Node* new_head, Node* head, unordered_map<Node*, Node*>& otn_map) {
        Node* new_node = NULL;
        if (head->next == NULL) {
            new_head->next = NULL;
        } else if (otn_map.find(head->next) == otn_map.end()) {
            new_node = new Node(head->next->val, NULL, NULL);
            new_head->next = new_node;
            otn_map[head->next] = new_node;
            _dfs(new_node, head->next, otn_map);
        } else {
            new_head->next = otn_map[head->next];
        }
        if (head->random == NULL) {
            new_head->random = NULL;
        } else if (otn_map.find(head->random) == otn_map.end()) {
            new_node = new Node(head->random->val, NULL, NULL);
            new_head->random = new_node;
            otn_map[head->random] = new_node;
            _dfs(new_node, head->random, otn_map);
        } else {
            new_head->random = otn_map[head->random];
        }
    }
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* new_head = new Node(head->val, NULL, NULL);
        unordered_map<Node*, Node*> otn_map;//old to new node map
        otn_map[head] = new_head;
        _dfs(new_head, head, otn_map);
        return new_head;
    }
};
