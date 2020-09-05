#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    void _bt(string& numbers, int start, string& cur_seg, int step, string& permutation, vector<string>& permutations) {
        if (step == 4) {
            if (start == numbers.length()) {
                permutations.push_back(permutation);
            }
            return;
        }
        for (int i = start; i < numbers.length(); i++) {
            swap(numbers[i], numbers[start]);
            cur_seg += numbers[start];

            if (cur_seg != "0" && cur_seg.length() < 3) {
                _bt(numbers, start + 1, cur_seg, step, permutation, permutations);
            }
            if (stoi(cur_seg) <= 255) {
                string new_permutation = cur_seg;
                if (permutation != "") {
                    new_permutation = permutation + "." + cur_seg;
                }
                string new_seg = "";
                _bt(numbers, start + 1, new_seg, step + 1, new_permutation, permutations);
            }
            
            cur_seg.pop_back();
            swap(numbers[i], numbers[start]);
        }
    }
public:
    vector<string> permutate(string numbers) {
        vector<string> permutations;
        string permutation = "";
        string cur_seg = "";
        _bt(numbers, 0, cur_seg, 0, permutation, permutations);
        return permutations;
    }
};

int main() {
    Solution s;
    auto results = s.permutate("012345");
    for (const string str : results) {
        cout << str << "\n";
    }
}
