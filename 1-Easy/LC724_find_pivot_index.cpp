// LeetCode Question: 724. Find Pivot Index
// Topics: Array, Prefix Sum

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int totalSum = 0;
        int n = nums.size();

        // Calculate total sum of array
        for(int i = 0; i < n; i++)
            totalSum += nums[i];

        // Traverse to find pivot index
        for(int i = 0; i < n; i++){
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
