class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        stack<int> stk;

        for (int i = 0; i < prices.size(); ++i) {            
            while (!stk.empty() && prices[i] < stk.top()) {
                stk.pop();
            }
            if (stk.empty()) {
                stk.push(prices[i]);
            }

            res = max(res, prices[i] - stk.top());
        }

        return res;
    }
};
