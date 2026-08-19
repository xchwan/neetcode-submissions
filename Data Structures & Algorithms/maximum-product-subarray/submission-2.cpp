class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        int dpMax = 0, dpMin = 0;

        dpMax = nums[0];
        dpMin = nums[0];

        for (int i = 1; i < n; ++i) {
            int candMax = max({nums[i], dpMax * nums[i], dpMin * nums[i]});
            int candMin = min({nums[i], dpMax * nums[i], dpMin * nums[i]});
            dpMax = candMax;
            dpMin = candMin;
            res = max(res, dpMax);
        }

        return res;
    }
};
