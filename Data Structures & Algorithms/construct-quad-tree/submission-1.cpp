/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* dfs(vector<vector<int>>& grid, int ibegin, int iend, int jbegin, int jend, Node* node) {
        bool isSame = true;
        int value = grid[ibegin][jbegin];
        for (int i = ibegin; i < iend && isSame; ++i) {
            for (int j = jbegin; j < jend; ++j) {
                if (grid[i][j] != value) {
                    isSame = false;
                    break;
                }
            }
        }

        if (isSame) {
            node->val = value;
            node->isLeaf = true;
        } else {
            node->val = 1;

            int imid = ibegin + (iend - ibegin) / 2;
            int jmid = jbegin + (jend - jbegin) / 2;

            node->topLeft = dfs(grid, ibegin, imid, jbegin, jmid, new Node());
            node->topRight = dfs(grid, ibegin, imid, jmid, jend, new Node());
            node->bottomLeft = dfs(grid, imid, iend, jbegin, jmid, new Node());
            node->bottomRight = dfs(grid, imid, iend, jmid, jend, new Node());
        }
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        Node* root = new Node();
        int n = grid.size();
        return dfs(grid, 0, n, 0, n, root);
    }
};