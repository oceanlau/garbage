class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        int mod = pow(10, 9) + 7;
        //tricky one, avoid overflow
        vector<long long> pow2;
        for (int i = 0; i < A.size(); i++) {
            if (pow2.empty()) {
                pow2.push_back(pow(2, i));
            } else {
                pow2.push_back((2 * pow2.back()) % mod);
            }
        }
        for (int i = 0; i < A.size(); i ++) {
            ans += (pow2[i] * A[i] - pow2[A.size() - i - 1] * A[i]) % mod;
            ans %= mod;
        }
        return ans;
    }
};

// tle
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        int mod = pow(10, 9) + 7;
        vector<int> pow2;
        for (int i = 1; i < A.size() - 1; i++) {
            if (pow2.empty()) {
                pow2.push_back(pow(2, i));
            } else {
                pow2.push_back(2 * pow2.back() % mod);
            }
        }
        for (int i = 0; i < A.size(); i ++) {
            for (int j = i; j < A.size(); j++) {
                int ways = 1;
                if (j - i > 1) {
                    ways = pow2[j - i - 2];
                }
                ans += (long long) ways * ((A[j] - A[i]) % mod) % mod;
                ans %= mod;
            }
        }
        return ans;
    }
};
