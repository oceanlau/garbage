/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* build(ListNode*& inorder, int l, int r) {
        if (inorder == NULL || r < l) {
            return NULL;
        }
        int mid = l + (r - l) / 2;
        TreeNode* left = build(inorder, l, mid - 1);
        TreeNode* root = new TreeNode(inorder->val);
        inorder = inorder->next;
        TreeNode* right = build(inorder, mid + 1, r);
        root->left = left;
        root->right = right;
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //inorder
        int cnt = 0;
        ListNode* inorder = head;
        while (head) {
            cnt ++;
            head = head->next;
        }
        return build(inorder, 0, cnt);
    }
};
