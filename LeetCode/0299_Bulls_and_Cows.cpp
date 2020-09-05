class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> counter;
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (guess[i] == secret[i]) {
                bulls ++;
            } else {
                counter[secret[i]] ++;
            }
        }
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] != secret[i] && counter[guess[i]] > 0) {
                cows ++;
                counter[guess[i]] --;
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> nums (10, 0);
        for (int i = 0; i < secret.length(); i++) {
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if (s == g) {
                bulls ++;
            } else {
                if (nums[s] < 0) {
                    cows ++;
                }
                if (nums[g] > 0) {
                    cows ++;
                }
                nums[s] ++;
                nums[g] --;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
