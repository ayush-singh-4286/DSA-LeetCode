// LeetCode 155 - Min Stack
// Topics: Stack, Design, Data Structure

class MinStack {
public:
    stack<int> s;
    stack<int> minS;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minS.empty() || minS.top() >= val)
            minS.push(val);
    }
    
    void pop() {
        if(s.top() == minS.top())
            minS.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};
