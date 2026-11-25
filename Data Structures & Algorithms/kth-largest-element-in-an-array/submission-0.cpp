class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pqMin;

        for (int num : nums) {
            pqMin.push(num);
            if ((int)pqMin.size() > k) {
                pqMin.pop();
            }
        }

        return pqMin.top();
    }
};
