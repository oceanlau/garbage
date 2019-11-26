/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    void _dfs(vector<NestedInteger>& nestedList, vector<int>& depth_sum, int depth) {
        if (depth > depth_sum.size()) {
            depth_sum.push_back(0);
        }
        for(int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                int integer = nestedList[i].getInteger();
                depth_sum[depth - 1] += integer;
            } else {
                //NestedInteger nest = nestedList.getList();
                _dfs(nestedList[i].getList(), depth_sum, depth + 1);
            }
        }
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> depth_sum;
        _dfs(nestedList, depth_sum, 1);
        int sum = 0;
        int mul = depth_sum.size();
        for (int i = 0; i < depth_sum.size(); i++) {
            sum += depth_sum[i] * (mul--);
        }
        return sum;
    }
};
