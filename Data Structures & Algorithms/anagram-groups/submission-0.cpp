class Solution {
    bool isAnagrams(string& s, string& t) {
        unordered_map<char, int> s_mp;
        unordered_map<char, int> t_mp;
        size_t n = s.size();

        if (s.size() != t.size()) return false;

        for (size_t i = 0; i < n; ++i) {
            ++s_mp[s[i]];
            ++t_mp[t[i]];
        }

        return s_mp == t_mp;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        
        for (int i = 0; i < n; ++i) {
            bool placed = false;
            for (int j = 0; j < res.size(); ++j) {
                if (isAnagrams(res[j][0], strs[i])) {
                    res[j].push_back(strs[i]);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                res.push_back({strs[i]});
            }
        }

        return res;
    }
};
