// LeetCode 682 - Baseball Game
// Topics: Stack, Simulation, Array

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int n = operations.size();

        for(int i = 0; i < n; i++){
            if(operations[i] == "C")
                s.pop();
            else if(operations[i] == "D"){
                int p = s.top() * 2;
                s.push(p);
            }
            else if(operations[i] == "+"){
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.push(top1);
                int p = top1 + top2;
                s.push(p);
            }
            else
                s.push(stoi(operations[i]));
        }

        int top = 0;
        while(!s.empty()){
            top += s.top();
            s.pop();
        }
        return top;
    }
};
