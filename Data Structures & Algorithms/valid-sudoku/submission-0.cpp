class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        unordered_map<int, unordered_set<char>> sqrts;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                int sqrtKey = (r / 3) * 3 + c / 3;

                if (rows[r].count(board[r][c]) || 
                    cols[c].count(board[r][c]) ||
                    sqrts[sqrtKey].count(board[r][c])
                ) {
                    return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                sqrts[sqrtKey].insert(board[r][c]);
            }
        }
        return true;
    }
};
