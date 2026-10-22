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
    vector<int> rightSideView(TreeNode* root) {
        // go fully down one level
        vector<int> result;
        queue<TreeNode *> q;
        if (root) q.push(root);
        while (!q.empty()) {
            result.push_back(q.front()->val);
            int level_size = q.size();
            // we are going to pop them all off, in this level we only want the far right one
            for (int i = 0; i < level_size; ++i) {
                // add their next nodes to the queue adding the farthest right first
                TreeNode *curr = q.front();
                if (curr->right) q.push(curr->right);
                if (curr->left) q.push(curr->left);
                q.pop(); // take off this front one
            }
        }
        return result;
    }
};