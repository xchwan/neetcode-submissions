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
    int dfs(TreeNode* node, int& ans) {
        if (!node) return 0;

        int leftMax = max(dfs(node->left, ans), 0);
        int rightMax = max(dfs(node->right, ans), 0);
        ans = max(ans, node->val + leftMax + rightMax);

        return node->val + max(leftMax, rightMax);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};
