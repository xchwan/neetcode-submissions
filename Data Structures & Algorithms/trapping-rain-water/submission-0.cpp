class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        int left, right, base;

        for (int i = 0; i < height.size(); ++i) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                base = height[stk.top()];
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                right = height[i];
                left = height[stk.top()];
                res += (min(left, right) - base) * (i - stk.top() - 1);
            }
            stk.push(i);
        }
        return res;
    }
};
