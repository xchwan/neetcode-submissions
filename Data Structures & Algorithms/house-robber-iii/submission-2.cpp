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
    pair<int, int> dfs(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }

        pair<int, int> leftres = dfs(node->left);
        pair<int, int> rightres = dfs(node->right);

        int wNode = node->val + leftres.second + rightres.second;
        int woNode = max(leftres.first, leftres.second) + max(rightres.first, rightres.second);

        return {wNode, woNode};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }
};