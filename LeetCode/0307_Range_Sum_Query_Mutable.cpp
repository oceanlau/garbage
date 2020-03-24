struct Node {
    int sum = 0;
    pair<int, int> range;
    Node* left = NULL;
    Node* right = NULL;
};

class NumArray {
private:
    Node* _root = NULL;
    Node* _build(int rangel, int ranger, vector<int>& nums) {
        Node* n = new Node();
        n->range = make_pair(rangel, ranger);
        if (rangel == ranger) {
            n->sum = nums[rangel];
        } else {
            int mid = rangel + (ranger - rangel) / 2;
            n->left = _build(rangel, mid, nums);
            n->right = _build(mid + 1, ranger, nums);
            n->sum = n->left->sum + n->right->sum;
        }
        return n;
    }
    void _update(Node* n, int i, int val) {
        int rangel = n->range.first;
        int ranger = n->range.second;
        if (rangel == ranger) {
            if (rangel == i) {
                n->sum = val;
            }
        } else {
            int mid = rangel + (ranger - rangel) / 2;
            if (mid < i) {
                _update(n->right, i, val);
            } else {
                _update(n->left, i, val);
            }
            n->sum = n->left->sum + n->right->sum;
        }
    }
    int _sumRange(Node* n, int i, int j) {
        int l = n->range.first;
        int r = n->range.second;
        if (l == i && r == j) {
            return n->sum;
        }
        int mid = l + (r - l) / 2;
        if (mid < i) {
            return _sumRange(n->right, i, j);
        } else if (mid >= j) {
            return _sumRange(n->left, i, j);
        }
        return _sumRange(n->left, i, mid) + _sumRange(n->right, mid + 1, j);
    }
public:
    NumArray(vector<int>& nums) {
        if (nums.size() != 0) {
            _root = _build(0, nums.size() - 1, nums);
        }
    }
    
    void update(int i, int val) {
        if (_root) {
            _update(_root, i, val);
        }
    }
    
    int sumRange(int i, int j) {
        if (_root) {
            return _sumRange(_root, i, j);
        }
        return -1;//undefined
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
