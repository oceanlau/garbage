//A或B，要么match A[0],要么match B[0]，分别检查
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int match_a0 = get_rotate(A[0], A, B);
        int match_b0 = get_rotate(B[0], A, B);
        if (match_a0 == -1) {
            if (match_b0 == -1) {
                return -1;
            }
            return match_b0;
        } else {
            if (match_b0 == -1) {
                return match_a0;
            }
            return min(match_a0, match_b0);
        }
        
    }
    int get_rotate(int val, vector<int>& A, vector<int>& B) {
        int rotate_A = 0;
        int rotate_B = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != val && B[i] != val) {
                return -1;
            }
            if (A[i] != val) {
                rotate_A ++;
            }
            if (B[i] != val) {
                rotate_B ++;
            }
        }
        return min(rotate_A, rotate_B);
    }
};
