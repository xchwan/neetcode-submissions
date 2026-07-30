class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int res = 0;

        int l = 0, highestFreq = 0;
        for (int r = 0; r < s.size(); ++r) {
            ++mp[s[r]];
            highestFreq = max(highestFreq, mp[s[r]]);

            while ((r - l + 1) - highestFreq > k) {
                --mp[s[l]];
                ++l;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
