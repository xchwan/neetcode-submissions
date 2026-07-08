class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for (int i = 0; i < strs.size(); ++i) {
            res += to_string(strs[i].size()) + '#' + strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                ++j;
            }

            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            
            i = j + 1 + len;
        }
        return res;
    }
};
