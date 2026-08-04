class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string token : tokens) {
            if (token == "+") {
                int second = stk.top(); stk.pop();
                int first = stk.top(); stk.pop();
                stk.push(first + second);
            } else if (token == "-") {
                int second = stk.top(); stk.pop();
                int first = stk.top(); stk.pop();
                stk.push(first - second);
            } else if (token == "*") {
                int second = stk.top(); stk.pop();
                int first = stk.top(); stk.pop();
                stk.push(first * second);
            } else if (token == "/") {
                int second = stk.top(); stk.pop();
                int first = stk.top(); stk.pop();
                stk.push(first / second);
            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};
