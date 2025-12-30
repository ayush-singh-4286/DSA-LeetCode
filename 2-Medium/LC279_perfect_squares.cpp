// LeetCode Question: 279 - Perfect Squares
// Topics: Dynamic Programming, Recursion, Memoization, Minimum Squares

class Solution {
    private:
    int solveRec(int n){
        // Base case
        if(n == 0)
        return 0;
        int mini=n;
        for(int i=1;i*i<=n;i++){
       int  ans=solveRec(n - i*i);
       mini=min(mini,1+ans);
        }
        return mini;
    }
    int solveMem(int n,vector<int>&dp){
        // Base case
        if(n == 0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        int mini=n;
        for(int i=1;i*i<=n;i++){
       mini=min(mini,1+solveMem(n - i*i,dp));
       dp[n]=mini;
        }
        return dp[n];
    }
    
public:
    int numSquares(int n) {
       // return solveRec(n);
        vector<int>dp(n+1,-1);
        return solveMem(n,dp);

    }
};
