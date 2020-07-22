class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        while (m > 0 || n > 0) {
            if (n == 0 || (m != 0 && nums1[m - 1] >= nums2[n - 1])) {
                nums1[i--] = nums1[m-- - 1];
            } else {
                nums1[i--] = nums2[n-- - 1];
            }
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = nums1.size() - 1; i >= 0; i --) {
            //careful!
            if (m >= 1 
                && (n < 1 || nums1[m - 1] >= nums2[n - 1])) {
                nums1[i] = nums1[m - 1];
                m--;
            } else {
                nums1[i] = nums2[n - 1];
                n--;
            }
        }
    }
};

// simple reversed thinking
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        m--;
        n--;
        while (pos >= 0) {
            if (m < 0) {
                nums1[pos--] = nums2[n--];
            } else if (n < 0) {
                nums1[pos--] = nums1[m--];
            } else if (nums1[m] < nums2[n]) {
                nums1[pos--] = nums2[n--];
            } else {
                nums1[pos--] = nums1[m--];
            }
        }
    }
};
