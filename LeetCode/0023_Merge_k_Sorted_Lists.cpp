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
