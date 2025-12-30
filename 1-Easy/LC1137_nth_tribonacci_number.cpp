// LeetCode Question: 1137 - N-th Tribonacci Number
// Topics: Recursion, Memoization, Tabulation, Space Optimization, Dynamic Programming

class Solution {
private:
    int recTrib(int n){
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;

        return recTrib(n-3) + recTrib(n-2) + recTrib(n-1);
    }

    int memTrib(int n, vector<int>& dp){
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        dp[n] = memTrib(n-3, dp) + memTrib(n-2, dp) + memTrib(n-1, dp);
        return dp[n];
    }

    int tabTrib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }

    int spaceOpt(int n){
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;

        for(int i = 3; i <= n; i++){
            int ans = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

public:
    int tribonacci(int n) {
        // return recTrib(n);
        // vector<int> dp(n+1,-1);
        // return memTrib(n, dp);

        // return tabTrib(n);
        return spaceOpt(n);
    }
};
