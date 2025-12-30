// LeetCode Question: 198 - House Robber
// Topics: Dynamic Programming, Recursion, Memoization, Space Optimization, DP on Linear Array

class Solution {
private:
    int optimisedCode(vector<int>& nums, int n){
        int prev2 = 0;
        int prev1 = nums[0];

        for(int i = 1; i < n; i++){
            int include = prev2 + nums[i];
            int exclude = prev1 + 0;

            prev2 = prev1;
            prev1 = max(include, exclude);
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return optimisedCode(nums, n);
    }
};
