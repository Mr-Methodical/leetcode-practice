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
    bool isValidSubtree(long long &lowest, TreeNode *root) {
        if (!root) return true;
        if (!isValidSubtree(lowest, root->left)) return false;
        if (root->val <= lowest) return false;
        lowest = root->val;
        if (!isValidSubtree(lowest, root->right)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long lowest = LLONG_MIN;
        return isValidSubtree(lowest, root);
    }
};