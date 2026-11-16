class Solution {
    bool dfs(vector<int>& m, int target, vector<int>& sides, int i) {
        int n = m.size();
        if (i == n) {
            return true;
        }

        for (int j = 0; j < 4; ++j) {
            if (m[i] + sides[j] > target) {
                continue;
            }

            bool isDupSide = false;
            for (int k = 0; k < j; ++k) {
                if (sides[k] == sides[j]) {
                    isDupSide = true;
                }
            }

            if (isDupSide) {
                continue;
            }

            sides[j] += m[i];
            if (dfs(m, target, sides, i + 1)) {
                return true;
            }
            sides[j] -= m[i];
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalSum % 4 != 0) {
            return false;
        }

        int target = totalSum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks[0] > target) {
            return false;
        }

        vector<int> sides(4, 0);
        return dfs(matchsticks, target, sides, 0);
    }
};