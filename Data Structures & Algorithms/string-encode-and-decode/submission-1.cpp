class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for (int i = 0; i < strs.size(); ++i) {
            res += strs[i] + '.';
        }

        return res;
    }

    vector<string> decode(string s) {

        istringstream iss(s);
        string item;
        vector<string> res;

        while(getline(iss, item, '.')) {
            res.push_back(item);
        }

        return res;
    }
};
