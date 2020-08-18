class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0;
        int j = 0;
        while (i < start.length() || j < end.length()) {
            while (i < start.length() && start[i] == 'X') {
                i ++;
            }
            while (j < end.length() && end[j] == 'X') {
                j ++;
            }
            if (i != start.length() && j != end.length()) {
                if (start[i] != end[j]) {
                    return false;
                }
                if (start[i] == 'R' && i > j) {
                    return false;
                }
                if (start[i] == 'L' && i < j) {
                    return false;
                }
            } else if (i != start.length() || j != end.length()) {
                return false;
            }
            i ++;
            j ++;
        }
        return true;
    }
};

class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0;
        int j = 0;
        while (i < start.length() || j < end.length()) {
            while (i < start.length() && start[i] == 'X') {
                i ++;
            }
            while (j < end.length() && end[j] == 'X') {
                j ++;
            }
            if ((i < start.length() && j == end.length()) || (i == start.length() && j < end.length())) {
                return false;
            } else if (start[i] != end[j]) {
                return false;
            } else if (start[i] == 'R' && i > j) {
                return false;
            } else if (start[i] == 'L' && i < j) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};
