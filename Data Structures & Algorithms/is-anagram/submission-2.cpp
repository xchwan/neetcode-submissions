class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_mp;
        unordered_map<char, int> t_mp;

        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.length(); i++) {
            s_mp[s[i]]++;
            t_mp[t[i]]++;
        }
        return s_mp == t_mp;
    }
};
