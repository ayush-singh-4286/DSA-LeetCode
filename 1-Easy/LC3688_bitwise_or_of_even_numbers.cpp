// LeetCode Question: Custom - Bitwise OR of Even Numbers
// Topics: Bit Manipulation, Array

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;

        // Iterate over all numbers and take OR of even numbers
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0)
                ans = ans | nums[i];
        }

        return ans;
    }
};
