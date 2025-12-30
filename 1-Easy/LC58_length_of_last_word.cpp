// LeetCode Question: 58. Length of Last Word
// Topics: String, Two Pointers, Traversal, Simulation

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        int ans = 0;

        // Skip trailing spaces
        while(i >= 0 && s[i] == ' ')
            i--;

        // Count the length of the last word
        while(i >= 0 && s[i] != ' ') {
            i--;
            ans++;
        }

        return ans;
    }
};
