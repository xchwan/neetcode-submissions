class Solution {
    int helper(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;

        for (int i = start; i <= end; ++i) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int first = helper(nums, 0, nums.size() - 2);
        int second = helper(nums, 1, nums.size() - 1);

        return max(first, second);
    }
};
