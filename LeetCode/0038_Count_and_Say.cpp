class Solution {
public:
    string countAndSay(int n) {
        string seq = "1";
        if (n == 1) {
            return seq;
        }
        while (n > 1) {
            char last_c = seq[0];
            int count = 1;
            string tmp_seq = "";
            for (int i = 1; i < seq.length(); i++) {
                if (seq[i] == last_c) {
                    count ++;
                    continue;
                }
                tmp_seq = tmp_seq + to_string(count) + last_c;
                count = 1;
                last_c = seq[i];
            }
            tmp_seq = tmp_seq + to_string(count) + last_c;
            seq = tmp_seq;
            n --;
        }
        return seq;
    }
};
