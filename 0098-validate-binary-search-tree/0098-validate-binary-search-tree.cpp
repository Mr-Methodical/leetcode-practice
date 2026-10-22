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
public:
    bool fallInRange(long long lower_bound, long long upper_bound, TreeNode *root) {
        if (!root) return true;
        if (lower_bound < static_cast<long long>(root->val) && 
            static_cast<long long>(root->val) < upper_bound) {
            return fallInRange(lower_bound, root->val, root->left) &&
                   fallInRange(root->val, upper_bound, root->right);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return fallInRange(LLONG_MIN, LLONG_MAX, root);
    }
};