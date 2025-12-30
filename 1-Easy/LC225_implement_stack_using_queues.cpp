// LeetCode 225 - Implement Stack using Queues
// Topics: Stack, Queue, Design, Data Structure

class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int del = q1.front();
        q1.pop();
        swap(q1, q2);
        return del;
    }
    
    int top() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int del = q1.front();
        q2.push(del);
        q1.pop();
        swap(q1, q2);
        return del;
    }
    
    bool empty() {
        return q2.empty() && q1.empty();
    }
};
