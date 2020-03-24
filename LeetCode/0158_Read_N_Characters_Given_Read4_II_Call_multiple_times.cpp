// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char buf4[4] = {0};
    int i4 = 0;
    int j4 = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            if (i4 < j4) {
                while (i < n && i4 < j4) {
                    buf[i++] = buf4[i4++];
                }
                if (j4 < 4) {
                    return i;
                }
            } else if (n - i >= 4) {
                //carefule
                int j = read4(buf + i);
                i += j;
                if (j < 4) {
                    return i;
                }
            } else {
                j4 = read4(buf4);
                i4 = 0;
                int toread = n - i;
                while (i4 < j4 && i4 < toread) {
                    buf[i++] = buf4[i4++];
                }
                if (j4 < 4) {
                    return i;
                }
            }
        }
        return i;
    }
};
