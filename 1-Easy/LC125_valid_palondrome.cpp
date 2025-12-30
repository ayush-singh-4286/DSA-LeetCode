// LeetCode Question: 125. Valid Palindrome
// Topics: String, Two Pointers, String Manipulation

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string ans = "";
        int x = 0;
        int n = s.size();
        while(x < n){
            if((s[x] >= 'a' && s[x] <= 'z') || (s[x] >= '0' && s[x] <= '9'))
                ans.push_back(s[x]);
            x++;
        }
            
        int m = ans.size();
        int i = 0, j = m - 1;
        while(i < j){
            if(ans[i] != ans[j])
                return false;

            i++;
            j--;
        } 
        return true;
    }
};
