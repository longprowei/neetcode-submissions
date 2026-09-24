class MinStack {
private:
    stack<int> coreStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        coreStack.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            if (val <= minStack.top()) {
                minStack.push(val);
            }
        }
    }
    
    void pop() {
        if (coreStack.top() == minStack.top()) {
            minStack.pop();
        }
        coreStack.pop();
    }
    
    int top() {
        return coreStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
