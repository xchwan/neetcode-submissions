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
    Node* dfs(vector<vector<int>>& prefixSum, int ibegin, int iend, int jbegin, int jend) {
        auto rangeSum = [&](int ib, int ie, int jb, int je) -> int {
            return prefixSum[ie][je] - prefixSum[ib][je] - prefixSum[ie][jb] + prefixSum[ib][jb];
        };

        int sqSize = (iend - ibegin) * (jend - jbegin);
        int sqSum = rangeSum(ibegin, iend, jbegin, jend);


        if (sqSum == sqSize || sqSum == 0) {
            return new Node(sqSum, true);
        }
        
        Node* node = new Node(true, false);

        int imid = ibegin + (iend - ibegin) / 2;
        int jmid = jbegin + (jend - jbegin) / 2;

        node->topLeft = dfs(prefixSum, ibegin, imid, jbegin, jmid);
        node->topRight = dfs(prefixSum, ibegin, imid, jmid, jend);
        node->bottomLeft = dfs(prefixSum, imid, iend, jbegin, jmid);
        node->bottomRight = dfs(prefixSum, imid, iend, jmid, jend);
        
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j] + grid[i][j];
            }
        }
        return dfs(prefixSum, 0, n, 0, n);
    }
};