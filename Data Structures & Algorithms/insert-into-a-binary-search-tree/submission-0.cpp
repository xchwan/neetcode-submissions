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
    void dfs(TreeNode* node, TreeNode* root) {
        if (node->val < root->val && root->left) {
            dfs(node, root->left);
        } else if (node->val > root->val && root->right) {
            dfs(node, root->right);
        } else if (node->val < root->val) {
            root->left = node;
        } else if (node->val > root->val) {
            root->right = node;
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);

        if (!root) return node;

        dfs(node, root);

        return root;
    }
};