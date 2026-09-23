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

class Codec {
    void dfs(TreeNode* node, string& res) {
        if (!node) {
            res+= "N;";
            return;
        }

        res += to_string(node->val) + ';';

        dfs(node->left, res);
        dfs(node->right, res);
    }

    TreeNode* build(vector<string>& dataVec, int& idx) {
        if (dataVec[idx] == "N" || idx >= dataVec.size()) {
            ++idx;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(dataVec[idx]));
        ++idx;
        node->left = build(dataVec, idx);
        node->right = build(dataVec, idx);

        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs(root, res);
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> dataVec;
        stringstream ss(data);
        string item;
        
        while (getline(ss, item, ';')) {
            dataVec.push_back(item);
        }

        int idx = 0;
        
        return build(dataVec, idx);
    }
};
