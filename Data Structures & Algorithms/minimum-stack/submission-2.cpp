class MinStack {
    long min;
    stack<long> stk;

public:
    MinStack() {}
    
    void push(int val) {
        if (stk.empty()) {
            stk.push(0);
            min = val;
        } else {
            stk.push((long)val - min);
            if (val < min) {
                min = val;
            }
        }
    }
    
    void pop() {
        if (stk.empty()) {
            return;
        }

        long pop = stk.top();
        stk.pop();

        if (pop < 0) {
            min = min - pop;
        }
    }
    
    int top() {
        long top = stk.top();
        return (int)(top > 0) ? (top + min) : min;
    }
    
    int getMin() {
        return (int)min;
    }
};
