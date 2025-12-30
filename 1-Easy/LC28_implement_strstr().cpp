// LeetCode Question: 28. Implement strStr()
// Topics: String, Substring Search, Two Pointers, Simulation

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = 0, j = 0;

        while(i < n) {
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j == m)
                    return i - m;
            }
            else {
                i = i - j + 1;
                j = 0;
            }
        }
        return -1;
    }
};
