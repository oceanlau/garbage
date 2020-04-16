class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        // dp
        if (A.size() < 2) {
            return 0;
        }
        int min_if_swap = 1;
        int min_if_no_swap = 0;
        for (int i = 1; i < A.size(); i++) {
            bool dont_need_exchange = (A[i - 1] < A[i] && B[i - 1] < B[i]);
            bool can_exchange = (B[i - 1] < A[i] && A[i - 1] < B[i]);
            if (dont_need_exchange && can_exchange) {
                int tmp_min_if_swap = min_if_swap;
                int tmp_min_if_no_swap = min_if_no_swap;
                min_if_swap = min(tmp_min_if_swap, tmp_min_if_no_swap) + 1;
                min_if_no_swap = min(tmp_min_if_swap, tmp_min_if_no_swap);
            } else if (dont_need_exchange) {
                // must exchange the prev one
                min_if_swap += 1;
                min_if_no_swap = min_if_no_swap;
            } else if (can_exchange) {
                int tmp_min_if_swap = min_if_swap;
                min_if_swap = min_if_no_swap + 1;
                min_if_no_swap = tmp_min_if_swap;
            }
        }
        return min(min_if_swap, min_if_no_swap);
    }
};
