/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
private:
    int binsearch(const ArrayReader& reader, int l, int r, int target) {
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            int val = reader.get(mid);
            if (val == target) {
                return mid;
            } else if (val > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (reader.get(l) == target) {
            return l;
        } else if (reader.get(r) == target) {
            return r;
        }
        return -1;
    }
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0;
        int r = 1;
        while (reader.get(r) < target) {
            l = r;
            r *= 2;
        }
        return binsearch(reader, l, r, target);
    }
};
