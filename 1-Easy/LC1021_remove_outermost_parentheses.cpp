// LeetCode Question: 1021. Remove Outermost Parentheses
// Topics: String, Stack, Parentheses Matching

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> stack;
        
        for (int i = 0; i < s.size(); i++) {
            char top = s[i];

            if (top == '(') {
                if (!stack.empty())  // not outermost '('
                    ans += top;
                stack.push(top);
            } 
            else { // top == ')'
                stack.pop();  // remove matching '('
                if (!stack.empty())  // not outermost ')'
                    ans += top;
            }
        }
        return ans;
    }
};
