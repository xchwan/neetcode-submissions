class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minVal = INT_MAX;

        for (int i = 0; i < prices.size(); ++i) {
            minVal = min(minVal, prices[i]);
            res = max(res, prices[i] - minVal);
        }

        return res;
    }
};
