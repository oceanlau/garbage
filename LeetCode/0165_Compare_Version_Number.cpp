class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream v1(version1);
        stringstream v2(version2);
        string v1_seg;
        string v2_seg;
        while (true) {
            if (getline(v1, v1_seg, '.')) {
                int v1_seg_n = stoi(v1_seg);
                if (getline(v2, v2_seg, '.')) {
                    int v2_seg_n = stoi(v2_seg);
                    if (v1_seg_n > v2_seg_n) {
                        return 1;
                    } else if (v1_seg_n < v2_seg_n) {
                        return -1;
                    }
                } else if (v1_seg_n > 0) {
                    return 1;
                }
            } else if (getline(v2, v2_seg, '.')) {
                int v2_seg_n = stoi(v2_seg);
                if (v2_seg_n > 0) {
                    return -1;
                }
            } else {
                break;
            }
        }
        return 0;
    }
};
