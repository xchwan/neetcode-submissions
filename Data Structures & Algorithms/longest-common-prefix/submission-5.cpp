class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        size_t min_size = strs[0].size();

        for (size_t j = 0; j < min_size; ++j) {
            for (int i = 1; i < n; ++i) {
                if (j >= strs[i].size() || strs[0][j] != strs[i][j]) {
                    return strs[0].substr(0, j);
                }
            }
        }
        return strs[0];
    }
};