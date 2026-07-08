class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        
        int res = 1;
        int consecutiveCount = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i - 1] == nums[i] - 1) {
                ++consecutiveCount;    
            } else {
                res = max(res, consecutiveCount);
                consecutiveCount = 1;
            }
        }

        res = max(res, consecutiveCount);

        return res;
    }
};
