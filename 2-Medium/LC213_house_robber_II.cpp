// LeetCode Question: 213 - House Robber II
// Topics: Dynamic Programming, Recursion, Memoization, Space Optimization, DP on Linear Array, Circular Array

class Solution {
private:
    int optimisedCode(vector<int>& nums){
        int n = nums.size();
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
        if(n == 1)
            return nums[0];

        vector<int> first, second;
        for(int i = 0; i < n; i++){
            if(i != n-1)
                first.push_back(nums[i]);
            if(i != 0)
                second.push_back(nums[i]);
        }
        return max(optimisedCode(first), optimisedCode(second));
    }
};
