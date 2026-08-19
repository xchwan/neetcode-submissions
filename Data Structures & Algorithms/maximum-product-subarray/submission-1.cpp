class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        vector<int> dpMax(n, 0);
        vector<int> dpMin(n, 0);

        dpMax[0] = nums[0];
        dpMin[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            dpMax[i] = max({nums[i], dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]});
            dpMin[i] = min({nums[i], dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]});
            res = max(res, dpMax[i]);
        }

        return res;
    }
};
