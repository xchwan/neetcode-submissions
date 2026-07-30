class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;

        for (char c : s1) {
            ++mp[c];
        }

        int l = 0;

        for (int r = 0; r < s2.size(); ++r) {
            while ((!mp.count(s2[r]) || mp[s2[r]] == 0) && l <= r) {
                if (mp.count(s2[l])) {
                    ++mp[s2[l]];
                }
                ++l;
            }
            if (mp.count(s2[r])) {
                --mp[s2[r]];
            }
            if (r - l + 1 == s1.size()){
                return true;
            }
        }
        return false;
    }
};
