class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); ++i) {
            ++freq[nums[i]];
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [num, count] : freq) {
            bucket[count].push_back(num);
        }

        vector<int> res;

        for (int i = nums.size(); i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                res.push_back(bucket[i][j]);

                if (res.size() == k) {
                    return res;
                }
            }
        }
        return {};
    }
};
