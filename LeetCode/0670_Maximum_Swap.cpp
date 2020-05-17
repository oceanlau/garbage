class Solution {
public:
    int maximumSwap(int num) {
        //from right to left, greedy find best candidate
        int maxidx = -1;
        char maxdigit = 0;
        int leftidx = -1;
        int rightidx = -1;
        string n = to_string(num);
        for (int i = n.length() - 1; i >= 0; i--) {
            if (n[i] > maxdigit) {
                maxidx = i;
                maxdigit = n[i];
                continue;
            }
            if (n[i] < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }
        if (leftidx != -1) {
            swap(n[leftidx], n[rightidx]);
        }
        return stoi(n);
        
    }
};
