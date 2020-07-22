class Solution {
public:
    string convert(string s, int numRows) {
        /*
        // each repeated pattern holds numRows + numRows - 2 num of chars
        // cal the number of patterns
        // outer loop iterate num of patterns, inc pointer num of chars every time
        // inner loop move the pointer to positions {
            +0,
            +1, + num of char - 1
            +2, + num of char - 2
            ...
            + numRows - 1
        }
        */
        string result = "";
        int num_chars = numRows + numRows - 2;
        if (numRows < 2) {
            num_chars = numRows;
        }
        int num_patterns = s.length() / num_chars + 1;
        for (int j = 0; j < numRows; j++) {
            for (int i = 0; i < num_patterns; i++) {
                if (i * num_chars + j >= s.length()) {
                    break;
                }
                result += s[i * num_chars + j];
                if (j == 0 || j == numRows - 1) {
                    continue;
                }
                if (i * num_chars + num_chars - j >= s.length()) {
                    break;
                }
                result += s[i * num_chars + num_chars - j];
            }
        }
        return result;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(len == 0 || numRows <= 1) {
            return s;
        }
        string result;
        result.reserve(len);
        //find the number of edges (a 'z' consists of 3 edges) and return ceil(numEdges)
        int numEdges = ((len - 1) + (numRows - 1) - 1) / (numRows - 1);
        //make sure all the 'z's are intact
        if (numEdges % 2 == 0) {
            numEdges ++;
        }
        int y = 0;
        while (y < numRows) {
            // the nth foot(bottom corner) of 'z'
            int x = 0;
            int lastPos = -1;
            while (x <= (numEdges - 1) / 2) {
                int leftPos = 2 * x * (numRows - 1) - y;
                if (leftPos < len && leftPos != lastPos && leftPos >= 0) {
                    result += s.at(leftPos);
                    lastPos = leftPos;
                }

                int rightPos = 2 * x * (numRows - 1) + y;
                if (rightPos < len && rightPos != lastPos) {
                    result += s.at(rightPos);
                    lastPos = rightPos;
                }
                x ++;
            }
            y ++;
        }
        return result;
    }
};
