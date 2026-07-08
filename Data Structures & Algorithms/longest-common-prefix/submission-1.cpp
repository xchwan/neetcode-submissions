class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int n = strs.size();
        size_t min_size = strs[0].size();
        bool stop = false;

        if (n == 1) {
            return strs[0];
        }
        
        for (int i = 1; i < n; ++i) {
            min_size = min(strs[i].size(), min_size);
        }

        for (int j = 0; j < min_size; ++j) {
            for (int i = 1; i < n; ++i) {
                if(strs[i - 1][j] != strs[i][j]) {
                    stop = true;
                    break;
                }
                if (i == n - 1) {
                    res += strs[i][j];
                }
            }
            if (stop) {
                break;
            }
        }
        return res;
    }
};