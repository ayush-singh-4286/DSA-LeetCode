// LeetCode Question: 136 - Single Number
// Topics: Array, Bit Manipulation, XOR

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = ans ^ nums[i]; // XOR cancels duplicates
        }
        return ans;
    }
};
