// LeetCode Question 344: Reverse String
// Topics: Two Pointers, String, Array

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        while(start <= end){
            swap(s[start], s[end]);
            start++;
            end--;
        } 
    }
};
