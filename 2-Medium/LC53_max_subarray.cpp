// LeetCode Question: 53 - Maximum Subarray
// Topics: Array, Dynamic Programming, Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);
            if(currentSum < 0)
                currentSum = 0;
        }
        return maxSum;
    }
};

