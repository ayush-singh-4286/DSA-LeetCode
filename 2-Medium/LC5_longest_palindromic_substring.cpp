// LeetCode 5 - Longest Palindromic Substring
// Topics: String, Dynamic Programming, Two Pointers, Expand Around Center

class Solution {
private:
    int expand(string s, int i, int j){
        int n = s.size();
        while(i >= 0 && j < n && s[i] == s[j]){
            i--;
            j++;
        }
        return j - i - 1;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 0;
        int start = 0;

        for(int i = 0; i < n; i++){
            int len1 = expand(s, i, i);     // Odd length palindrome
            int len2 = expand(s, i, i + 1); // Even length palindrome
            int currLength = max(len1, len2);

            if(currLength > maxLength){
                maxLength = currLength;
                start = i - (currLength - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
