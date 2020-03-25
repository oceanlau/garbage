struct Node {
    int val = 0;
    int dupe_cnt = 0;
    int left_children_cnt = 0;
    Node* left = NULL;
    Node* right = NULL;
    Node (int _val) : val(_val), dupe_cnt(1) {}
};
class Solution {
private:
    Node* _root = NULL;
    int _insert(Node*& n, int num) {
        if (n == NULL) {
            n = new Node(num);
            return 0;
        }
        if (n->val == num) {
            n->dupe_cnt ++;
            return n->left_children_cnt;
        } else if (n->val < num) {
            return n->dupe_cnt + n->left_children_cnt + _insert(n->right, num);
        }
        n->left_children_cnt ++;
        return _insert(n->left, num);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts = nums;
        for (int i = nums.size() - 1; i >= 0; i--) {
            counts[i] = _insert(_root, nums[i]);
        }
        return counts;
    }
};
