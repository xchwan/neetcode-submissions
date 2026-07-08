class Solution {
public:
    bool isPalindrome(string s) {
        string sAlpha;

        for (int i = 0; i < s.size(); ++i) {
            if (isalnum(s[i])) {
                sAlpha += tolower(s[i]);
            }
        }

        int n = sAlpha.size();

        for (int i = 0; i < n/2; ++i) {
            if (sAlpha[i] != sAlpha[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
