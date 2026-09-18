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
    TreeNode* build(int pl, int pr, int il, int ir, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderMp) {
        if (pl > pr) return nullptr;

        TreeNode* node = new TreeNode(preorder[pl]);
        int mid = inorderMp[node->val];
        int pLeftShift = mid - il;

        node->left = build(pl + 1, pl + pLeftShift, il, mid - 1, preorder, inorder, inorderMp);
        node->right = build(pl + pLeftShift + 1, pr, mid + 1, ir, preorder, inorder, inorderMp);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {       
        int n = inorder.size();
        if (preorder.empty()) return nullptr;

        unordered_map<int, int> inorderMp;

        for (int i = 0; i < n; ++i) {
            int val = inorder[i];
            inorderMp[val] = i; 
        }

        return build(0, n - 1, 0, n - 1, preorder, inorder, inorderMp);
    }
};
