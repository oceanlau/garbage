class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int i_start = 0;
        int i_end = len1;
        //double:
        //https://stackoverflow.com/questions/7571326/why-does-dividing-two-int-not-yield-the-right-value-when-assigned-to-double
        double min_right;
        double max_left;

        while (i_start <= i_end) {
            //binary search
            int i = (i_start + i_end) / 2;
            int j = (len1 + len2) / 2 - i;
            if (i > 0 && nums1[i - 1] > nums2[j]) {
                i_end = i - 1;
            } else if (i < len1 && nums2[j - 1] > nums1[i]) {
                i_start = i + 1;
            } else {
                //perfect i and j
                //brutal enumeration method to get final result:
                if((len1 + len2) % 2 == 1) {
                    //include condition: len1 == 0
                    if (i == len1) {
                        return nums2[j];
                    } else {
                        return min(nums1[i], nums2[j]);
                    }
                } else {
                     if (len1 == 0) {
                        min_right = nums2[j];
                        max_left = nums2[j - 1];
                    } else if (i == 0) {
                        if (j == len2) {
                            min_right = nums1[i];
                        } else {
                            min_right = min(nums1[i], nums2[j]);
                        }

                        max_left = nums2[j - 1];
                    } else if (i == len1) {
                        if (j == 0) {
                            max_left = nums1[i - 1];
                        } else {
                            max_left = max(nums1[i - 1], nums2[j - 1]);
                        }
                        min_right = nums2[j];
                    } else {
                        min_right = min(nums1[i], nums2[j]);
                        max_left = max(nums1[i - 1], nums2[j - 1]);
                    }
                    return (min_right + max_left) / 2;
                }
            }
        }
    }
};
