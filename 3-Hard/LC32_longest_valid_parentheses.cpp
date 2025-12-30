// LeetCode Question 32: Longest Valid Parentheses
// Topics: Stack, String, Dynamic Programming Concept (for length calculation)

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base case to handle valid substrings at the start
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push index of '('
            } else {
                st.pop(); // Pop last unmatched '(' or the base case
                if (st.empty()) {
                    st.push(i); // Push current index as new base
                } else {
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }
        return maxLength;
    }
};
