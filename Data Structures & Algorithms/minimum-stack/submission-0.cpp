class MinStack {
    stack<int> stk;
    stack<int> minStk;

public:
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        int miniVal = min(val, minStk.empty() ? val : minStk.top());
        minStk.push(miniVal);
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
