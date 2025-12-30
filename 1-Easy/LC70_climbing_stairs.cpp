// LeetCode Question: 70. Climbing Stairs
// Topics: Recursion, Dynamic Programming, Memoization

class Solution {
private:
    int recursive(int n){
        if(n == 0 || n == 1)
            return 1;

        return recursive(n-1) + recursive(n-2);
    }

    int memFunction(int n, vector<int>& dp){
        if(n == 0 || n == 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];

        dp[n] = memFunction(n-1, dp) + memFunction(n-2, dp);
        return dp[n];    
    }

public:
    int climbStairs(int n) {
        // return recursive(n);

        vector<int> dp(n+1, -1);
        return memFunction(n, dp);
    }
};
