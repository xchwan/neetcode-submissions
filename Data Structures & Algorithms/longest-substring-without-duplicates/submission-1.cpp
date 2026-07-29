class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, res = 0;
        unordered_set<char> used;

        for (int r = 0; r < s.size(); ++r) {
            while (used.count(s[r])) {
                used.erase(s[l]);
                ++l;
            }

            used.insert(s[r]);
            res = max(res, r - l + 1);
        }

        return res;
    }
};
