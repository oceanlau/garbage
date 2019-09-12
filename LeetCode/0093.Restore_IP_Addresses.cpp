class Solution {
private:
    //result join by '.', then push into results
    void _get_segment(vector<string>& results, vector<string>& result, string input, int input_size, int nth_segment, int nth_input) {
        if (nth_segment == 4) {
            stringstream s;
            s << result[0];
            int i = 1;
            while (i < 4) {
                s << '.' << result[i];
                i++;
            }
            results.push_back(s.str());
            return;
        }
        if (input_size - nth_input - 3*(4-nth_segment-1) > 3) {
            return;
        }
        int steps = 1;
        int steps_max = input_size - nth_input - (4-nth_segment-1);
        if (steps_max < 1) {
            return;
        } else if (steps_max > 3) {
            if (nth_segment == 3) {
                return;
            }
            steps_max = 3;
        }
        if (nth_segment == 3) {
            if (input[nth_input] == '0' && steps_max > 1) {
                return;
            }
            steps = steps_max;
        }
        if (input[nth_input] == '0') {
            steps_max = 1;
        }
        for (; steps <= steps_max; steps++) {
            string substring = input.substr(nth_input, steps);
            if (stoi(substring) > 255) {
                return;
            }
            result[nth_segment] = substring;
            _get_segment(results, result, input, input_size, nth_segment + 1, nth_input + steps);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results {};
        vector<string> result (4, "");
        _get_segment(results, result, s, s.length(), 0, 0);
        return results;
    }
};
