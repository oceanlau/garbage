/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int _lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& lca) {
        TreeNode* proposed = NULL;
        int counter = 0;
        if (root->left) {
            counter += _lca(root->left, p, q, lca);
        }
        if (lca != NULL) {
            return counter;
        }
        if (root->right) {
            counter += _lca(root->right, p, q, lca);
        }
        if (lca != NULL) {
            return counter;
        }
        if (root->val == p->val || root->val == q->val) {
            counter += 1;
        }
        if (counter == 2) {
            lca = root;
        }
        return counter;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = NULL;
        _lca(root, p, q, lca);
        return lca;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//DFS, first node return 2 (both found)
class Solution {
private:
    int _find(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& lca) {
        int match_cnt = 0;
        if (node->val == p->val || node->val == q->val) {
            match_cnt ++;
        }
        if (node->left) {
            match_cnt += _find(node->left, p, q, lca);
        }
        if (lca) {
            return 2;
        }
        if (node->right) {
            match_cnt += _find(node->right, p, q, lca);
        }
        if (lca) {
            return 2;
        }
        if (match_cnt == 2) {
            lca = node;
        }
        return match_cnt;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = NULL;
        _find(root, p, q, lca);
        return lca;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    /*
    bool _dfs(TreeNode* root, TreeNode* last_dfs, TreeNode* target) {
        if ()
    }*/
    TreeNode* _lca_find(stack<TreeNode*>& ancestors, TreeNode* target) {
        TreeNode* last_dfs = NULL;
        while(!ancestors.empty()) {
            
            /*
            if (_dfs(ancestors.top(), last_dfs, target)) {
                return ancestors.top();
            }*/
            TreeNode* cur = ancestors.top();
            stack<TreeNode*> nodes;
            while (cur) {
                if (cur == target) {
                    return ancestors.top();
                }
                nodes.push(cur);
                if (cur->left != last_dfs) {
                    cur = cur->left;
                } else {
                    cur = NULL;
                }
            }
            while (!nodes.empty()) {
                cur = nodes.top();
                nodes.pop();
                if (cur->right != last_dfs) {
                    cur = cur->right;
                    while (cur) {
                        if (cur == target) {
                            return ancestors.top();
                        }
                        nodes.push(cur);
                        cur = cur->left;
                    }
                }
            }
                
            last_dfs = ancestors.top();
            ancestors.pop();
        }
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //naive way, find two, add parent pointers in the process, reverse find root while recording a map # solution 2
        //dont use parent pointers, use a stack or other container to record the path to one element, then pop each one and find the next #like solution 3
        //other, simple recursive with two flag! like solution 1
        //recursive super simple! https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/65225/4-lines-C%2B%2BJavaPythonRuby
        if (root == p || root == q) {
            return root;
        }
        stack<TreeNode*> ancestors;
        while (root) {
            ancestors.push(root);
            if (root == p) {
                return _lca_find(ancestors, q);
            } else if (root == q) {
                return _lca_find(ancestors, p);
            }
            root = root->left;
        }
        while (!ancestors.empty()) {
            TreeNode* cur = ancestors.top();
            ancestors.pop();
            TreeNode* new_cur = cur->right;
            while (new_cur) {
                ancestors.push(new_cur);
                if (new_cur == p) {
                    return _lca_find(ancestors, q);
                } else if (new_cur == q) {
                    return _lca_find(ancestors, p);
                }
                new_cur = new_cur->left;
            }
        }
        return NULL;
    }
};

//40% 90%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int _dfs(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* & ans) {
        if (ans != NULL) {
            return 2;
        }
        if (node == NULL) {
            return 0;
        }
        int indicator = 0;
        if (node->val == p->val) {
            indicator++;
        }
        if (node->val == q->val) {
            indicator++;
        }
        if (indicator < 2) {
            indicator += _dfs(node->left, p, q, ans);
        }
        if (indicator < 2) {
            indicator += _dfs(node->right, p, q, ans);
        }
        if (indicator >= 2 && ans == NULL) {
            ans = node;
            return 2;
        }
        return indicator;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        _dfs(root, p, q, ans);
        return ans;
        //_dfs on left and right
        //_dfs should return if we find p or q
        // if tree nodes are uniq, _dfs return number. if node->val == p or q and _dfs return 1, set ans. if _dfs left and right both return 1, set ans
        // set ans if ans is null
        
        // if tree nodes are not uniq, _dfs return a vector of bool. if both position are true or node->val makes them true, set ans
    }
};

//73% 76%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int _dfs(TreeNode*& res, TreeNode* node, TreeNode* p, TreeNode* q) {
        int ind = 0;
        if (node->val == p->val) {
            ind ++;
        }
        if (node->val == q->val) {
            ind ++;
        }
        if (node->left != NULL) {
            ind += _dfs(res, node->left, p, q);
        }
        if (ind < 2 && node->right != NULL) {
            ind += _dfs(res, node->right, p, q);
        }
        if (res == NULL && ind >= 2) {
            res = node;
        }
        return ind;
    }
    //int indicator 0 - not found, 1 - found 1, 2 found 2 _dfs(*res, node, p, q) {
        // this_ind = 0
        // if node = p, this id++
        // if node = q, this id++
        // if l exists idl = _dfs(l)
        // if r exists idl = _dfs(r)
        // if res == null && id sum == 2, res = this node
        // return id sum
        // 
    //}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        if (_dfs(res, root, p, q) >= 2) {
            return res;
        }
        return NULL;
    }
};
