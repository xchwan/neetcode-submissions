class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int n = strs.size();
        size_t min_size = strs[0].size();
        
        for (int i = 1; i < n; ++i) {
            min_size = min(strs[i].size(), min_size);
        }

        for (size_t j = 0; j < min_size; ++j) {
            for (int i = 1; i < n; ++i) {
                if (strs[0][j] != strs[i][j]) {
                    return strs[0].substr(0, j);
                }
            }
        }
        return strs[0].substr(0, min_size);
    }
};