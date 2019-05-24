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
