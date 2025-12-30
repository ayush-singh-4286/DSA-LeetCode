// LeetCode Question: 1614. Maximum Nesting Depth of the Parentheses
// Topics: String, Stack, Simulation

class Solution {
public:
    int maxDepth(string s) {
        int tempCount = 0;
        int count = 0;
        stack<char> stk;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch == '(') {
                stk.push(ch);
                tempCount++;
            }
            else if(ch == ')') {
                count = max(count, tempCount);
                if(!stk.empty()) {
                    stk.pop();
                    tempCount--;
                }
            }
        }
        return count;
    }
};
