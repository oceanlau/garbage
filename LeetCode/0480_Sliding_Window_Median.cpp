class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        multiset<int> window (nums.begin(), nums.begin() + k);
        
        auto mid = next(window.begin(), k / 2);
        if (k % 2 == 0) {
            auto lower_mid = mid;
            lower_mid --;
            medians.push_back(((double)*lower_mid + (double)*mid) / 2.0);
        } else {
            medians.push_back(*mid);
        }
        
        for (int i = k; i < nums.size(); i++) {
            int newbie = nums[i];
            int retired = nums[i - k];
            window.insert(newbie);
            
            //insert new one before mid
            if (newbie < *mid) {
                // special case, escape from being removed
                if (retired == *mid) {
                    mid ++;
                    window.erase(window.lower_bound(retired));
                    mid --;
                } else {
                    if (retired > *mid) {
                        mid --;
                    }
                    window.erase(window.lower_bound(retired));
                }
            } else {//new one after mid
                // remove before mid
                if (retired <= *mid) {
                    mid ++;
                }
                window.erase(window.lower_bound(retired));
            }
            
            
            if (k % 2 == 0) {
                auto lower_mid = mid;
                lower_mid --;
                medians.push_back(((double)*lower_mid + (double)*mid) / 2.0);
            } else {
                medians.push_back(*mid);
            }
        }
        
        return medians;
    }
};
