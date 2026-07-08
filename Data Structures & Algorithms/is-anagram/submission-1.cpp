class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_mp;
        unordered_map<char, int> t_mp;

        if (s.size() != t.size()) return false;

        for (char w : s) {
            ++s_mp[w];
        }

        for (char w : t) {
            ++t_mp[w];
        }

        for (auto [k, v] : s_mp) {
            if (t_mp[k] != v) {
                return false;
            }
        }
        return true;
    }
};
