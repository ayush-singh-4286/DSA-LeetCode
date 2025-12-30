// LeetCode Question 9: Palindrome Number
// Topics: Math, Number Manipulation, Integer Reversal

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        int n = x;
        int ans = 0;

        while(n != 0) {
            int digit = n % 10;
            n = n / 10;
            if(ans < INT_MAX / 10) // prevent overflow
                ans = (ans * 10) + digit;
        }
        

        return ans == x;
    }
};
