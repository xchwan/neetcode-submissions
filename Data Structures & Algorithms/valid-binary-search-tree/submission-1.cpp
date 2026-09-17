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
    bool dfs(TreeNode* node, TreeNode* maxNode, TreeNode* minNode) {
        if (!node) return true;
        if (maxNode && node->val >= maxNode->val) return false;
        if (minNode && node->val <= minNode->val) return false;
        return dfs(node->left, node, minNode) && dfs(node->right, maxNode, node);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
};
