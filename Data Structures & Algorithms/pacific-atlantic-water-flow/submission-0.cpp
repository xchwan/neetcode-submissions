class Solution {
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& canflow, vector<pair<int, int>> dirs, int m, int n) {
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            canflow[r][c] = true;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nc >= 0 && nr < m && nc < n && !canflow[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int, int>> qPac;
        queue<pair<int, int>> qAtl;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<bool>> canPac(m, vector<bool>(n, false));
        vector<vector<bool>> canAtl(m, vector<bool>(n, false));

        for (int c = 0; c < n; ++c) {
            qPac.push({0, c});
            qAtl.push({m - 1, c});
        }

        for (int r = 0; r < m; ++r) {
            qPac.push({r, 0});
            qAtl.push({r, n - 1});
        }

        bfs(heights, qPac, canPac, dirs, m, n);
        bfs(heights, qAtl, canAtl, dirs, m, n);

        vector<vector<int>> res;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (canPac[r][c] && canAtl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
