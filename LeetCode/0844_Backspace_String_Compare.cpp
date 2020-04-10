class Solution {
private:
    int backspace(string str, int pos) {
        int backspace_cnt = 0;
        while (pos >= 0 && (str[pos] == '#' || backspace_cnt > 0)) {
            if (str[pos] == '#') {
                backspace_cnt ++;
            } else {
                backspace_cnt --;
            }
            pos--;
        }
        return pos;
    }
public:
    bool backspaceCompare(string S, string T) {
        int s = S.length() - 1;
        int t = T.length() - 1;
        while (true) {
            s = backspace(S, s);
            t = backspace(T, t);
            if (s >= 0 && t >= 0) {
                if (S[s] != T[t]) {
                    return false;
                }
                s --;
                t --;
            } else {
                break;
            }
        }
        if (s != -1 || t != -1) {
            return false;
        }
        return true;
    }
};

class Solution {
private:
    int backspace(string str, int pos) {
        int backspace_cnt = 0;
        while (pos >= 0 && (str[pos] == '#' || backspace_cnt > 0)) {
            if (str[pos] == '#') {
                backspace_cnt ++;
            } else {
                backspace_cnt --;
            }
            pos--;
        }
        return pos;
    }
public:
    bool backspaceCompare(string S, string T) {
        int s = S.length() - 1;
        int t = T.length() - 1;
        while (s >= 0 || t >= 0) {
            s = backspace(S, s);
            t = backspace(T, t);
            if (s >= 0 && t >= 0) {
                if (S[s] != T[t]) {
                    return false;
                }
                s --;
                t --;
            } else if (s >= 0 && S[s] != '#') {
                return false;
            } else if (t >= 0 && T[t] != '#') {
                return false;
            }
        }
        /*
        if (s != -1 || t != -1) {
            return false;
        }*/
        return true;
    }
};

