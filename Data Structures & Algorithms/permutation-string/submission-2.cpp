class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> needS1(26, 0);
        vector<int> haveS2(26, 0);

        int n = s1.size(), matches = 0;

        for (int i = 0; i < n; ++i) {
            ++needS1[s1[i] - 'a'];
            ++haveS2[s2[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (needS1[i] == haveS2[i]) {
                ++matches;
            }
        }

        int l = 0;
        for (int r = n; r < s2.size(); ++r) {
            if (matches == 26) {
                return true;
            }

            int idx = s2[r] - 'a';
            ++haveS2[idx];
            if (needS1[idx] == haveS2[idx]) {
                ++matches;
            }else if (needS1[idx] + 1 == haveS2[idx]) {
                --matches;
            }

            idx = s2[l] - 'a';
            --haveS2[idx];
            if (needS1[idx] == haveS2[idx]) {
                ++matches;
            }else if (needS1[idx] - 1 == haveS2[idx]) {
                --matches;
            }
            ++l;
        }
        return matches == 26;
    }
};
