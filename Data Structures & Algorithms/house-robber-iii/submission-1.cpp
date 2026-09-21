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
    int dfs(TreeNode* node, unordered_map<TreeNode*, int>& memo) {
        if (!node) return 0;
        if (memo.count(node)) return memo[node];

        int res = node->val;

        if (node->left) {
            res += dfs(node->left->left, memo) + dfs(node->left->right, memo);
        }
        if (node->right) {
            res += dfs(node->right->left, memo) + dfs(node->right->right, memo);
        }

        res = max(res, dfs(node->left, memo) + dfs(node->right, memo));

        return memo[node] = res;
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        memo[nullptr] = 0;
        return dfs(root, memo);
    }
};