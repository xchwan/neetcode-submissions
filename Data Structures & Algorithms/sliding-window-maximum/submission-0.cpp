class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> que;

        int i = 0;

        while(i < k) {
            while(!que.empty() && nums[i] > que.back()) {
                que.pop_back();
            }
            que.push_back(nums[i]);
            ++i;
        }
        res.push_back(que.front());

        int j = 0;

        while(j < nums.size() - k) {
            if (que.front() == nums[j]) {
                que.pop_front();
            }
            while (!que.empty() && nums[j + k] > que.back()) {
                que.pop_back();
            }
            que.push_back(nums[j + k]);
            res.push_back(que.front());
            ++j;
        }
        return res;
    }
};
