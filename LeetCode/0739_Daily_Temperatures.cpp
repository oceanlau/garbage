class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> mono_dec_pos;
        for(int i = 0; i < T.size(); i++) {
            while (mono_dec_pos.size() != 0 && T[mono_dec_pos.top()] < T[i]) {
                T[mono_dec_pos.top()] = i - mono_dec_pos.top();
                mono_dec_pos.pop();
            }
            mono_dec_pos.push(i);
        }
        while (mono_dec_pos.size() != 0) {
            T[mono_dec_pos.top()] = 0;
            mono_dec_pos.pop();
        }
        return T;
    }
};
