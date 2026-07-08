class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            if (mp.count(target - nums[i])) {
                res.push_back(mp[target - nums[i]]);
                res.push_back(i);
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
