class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        stack<int> stk;

        for (int i = 0; i <= n; ++i) {
            while (!stk.empty() && (i == n || heights[stk.top()] >= heights[i])) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1; //stk.top()是彈出後的top
                res = max(res, h * w);
            }
            stk.push(i);
        }
        return res;
    }
};
