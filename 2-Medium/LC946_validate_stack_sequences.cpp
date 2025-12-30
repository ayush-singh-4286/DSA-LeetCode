// LeetCode 946 - Validate Stack Sequences
// Topics: Stack, Simulation, Array

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        int m = popped.size();

        for(int i = 0; i < pushed.size(); i++){
            s.push(pushed[i]);
            while(!s.empty() && s.top() == popped[j] && j < m){
                s.pop();
                j++;
            }
        }

        while(!s.empty() && j < m){
            if(s.top() != popped[j])
                return false;
            else{
                j++;
                s.pop();
            }
        }

        return true;
    }
};
