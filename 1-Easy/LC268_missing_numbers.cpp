// LeetCode Question: 268. Missing Number
// Topics: Array, Math, Prefix Sum

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int prefixSum = nums[0];
        
        // Calculate sum of given array
        for(int i = 1; i < n; i++)
            prefixSum += nums[i];

        // Calculate sum of first n natural numbers
        int totalSum = n * (n + 1) / 2;

        // Missing number = totalSum - prefixSum
        return totalSum - prefixSum;
    }
};
