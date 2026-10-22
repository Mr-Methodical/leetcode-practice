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
    void dfs(TreeNode *root, vector<int> &result, size_t level) {
        if (!root) return;
        // this would be the first one that we found on the right
        if (level == result.size()) {
            result.push_back(root->val);
        }
        // else the level is less than 
        if (root->right) dfs(root->right, result, level + 1);
        if (root->left) dfs(root->left, result, level + 1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, result, 0);
        return result;
    }
};