class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_pos(26, -1);
        for (int i = S.length() - 1; i >= 0; i --) {
            if (last_pos[S[i] - 'a'] == -1) {
                last_pos[S[i] - 'a'] = i;
            }
        }
        vector<int> part_lens;
        for (int i = 0; i < S.length(); i ++) {
            int part_end = last_pos[S[i] - 'a'];
            for (int j = i + 1; j <= part_end; j ++) {
                part_end = max(part_end, last_pos[S[j] - 'a']);
            }
            part_lens.push_back(part_end - i + 1);
            i = part_end;
        }
        return part_lens;
    }
};
