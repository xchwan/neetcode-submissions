class Solution {
    bool dfs(vector<int>& nums, int target, int i, int cnt, int curr, vector<bool>& used) {
        int n = nums.size();

        if (cnt == n) {
            return true;
        }

        if (curr == target) {
            return dfs(nums, target, 0, cnt, 0, used);
        }

        for (int j = i; j < n; ++j) {
            if (used[j] || curr + nums[j] > target) {
                continue;
            }

            if (j > 0 && nums[j - 1] == nums[j] && !used[j - 1]) {
                continue;
            }

            used[j] = true;
            if (dfs(nums, target, i + 1, cnt + 1, curr + nums[j], used)) {
                return true;
            }
            used[j] = false;

            if (curr == 0) {
                return false;
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;

        int target = total / k;
        sort(nums.rbegin(), nums.rend());

        int n = nums.size();

        vector<bool> used(n, false);
        return dfs(nums, target, 0, 0, 0, used);
    }
};