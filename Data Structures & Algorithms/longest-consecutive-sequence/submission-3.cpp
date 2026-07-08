class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;

        for (int num: numSet) {
            if (!numSet.count(num - 1)) {
                int len = 1;
                while (numSet.count(num + len)) {
                    ++len;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};
