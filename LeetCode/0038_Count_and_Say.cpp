class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        n --;
        while (n > 0) {
            string next = "";
            char num = '0';
            for (int i = 0; i < cur.length(); i++) {
                num ++;
                if (i + 1 == cur.length() || cur[i + 1] != cur[i]) {
                    next += num;
                    next += cur[i];
                    num = '0';
                }
            }
            cur = next;
            n --;
        }
        return cur;
    }
};

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
