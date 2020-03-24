/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        for (const auto& node : lists) {
            if (node) {
                pq.emplace(-node->val, node);
            }
        }
        ListNode* head = NULL;
        ListNode* node = NULL;
        while (!pq.empty()) {
            if (head == NULL) {
                head = pq.top().second;
                node = head;
            } else {
                node->next = pq.top().second;
                node = node->next;
            }
            pq.pop();
            if (node->next) {
                pq.emplace(-node->next->val, node->next);
            }
        }
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // sps vector size N, list length L
        // naive, O(LN*N)
        // min heap, O(LN*log N)
        auto comp = [] (const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> heads(comp);
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                heads.push(lists[i]);
            }
        }
        ListNode* head = NULL;
        ListNode* node = NULL;
        while (true) {
            if (heads.size() == 0) {
                break;
            }
            ListNode* cur = heads.top();
            heads.pop();
            if (cur->next != NULL) {
                heads.push(cur->next);
            }
            if (head == NULL) {
                head = cur;
                node = head;
            } else {
                node->next = cur;
                node = node->next;
            }
        }
        return head;
    }
};

// Slow
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        ListNode* h = NULL;
        ListNode* loop = NULL;
        
        while (true) {
            bool is_processing = false;
            int n = lists.size() - 1;
            int min_idx = 0;
            int min_val = INT_MAX;
            while (n >= 0) {
                if (lists[n] == NULL) {
                    n --;
                    continue;
                }
                is_processing = true;
                if (lists[n]->val < min_val) {
                    min_idx = n;
                    min_val = lists[min_idx]->val;
                }
                n --;
            }
            if (h == NULL) {
                loop = lists[min_idx];
                h = loop;
            } else {
                loop->next = lists[min_idx];
                loop = loop->next;
            }
            if (!is_processing) {
                break;
            } else {  
                lists[min_idx] = lists[min_idx]->next;
            }
        }
        
        return h;
    }
};

// Improve With Priority Queue

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;
        
        for (ListNode*& l : lists) {
            if (l) {
                q.push(l);
            }
        }
        
        ListNode* loop = NULL;
        ListNode* h = NULL;
        while (!q.empty()) {
            if (h == NULL) {
                loop = q.top();
                h = loop;
            } else {
                loop->next = q.top();
                loop = loop->next;
            }
            q.pop();
            if (loop->next != NULL) {
                q.push(loop->next);
            }
        }
        return h;
    }
private:
    struct Compare {
        bool operator()(ListNode* & lhs, ListNode* & rhs) {
            return lhs->val > rhs->val;
        }
    };
};
