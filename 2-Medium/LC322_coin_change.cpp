// LeetCode Question: 322 - Coin Change
// Topics: Dynamic Programming, Recursion, Memoization

class Solution {
    private:
    int solveRec(vector<int>& coins, int amount){
        if(amount == 0)
        return 0;
        if(amount<0)
        return INT_MAX;
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
           int subAns=solveRec(coins,amount-coins[i]);
           if(subAns!=INT_MAX)
           ans=min(ans,1+subAns);
        }
        return ans;
    }
    int solveMem(vector<int>& coins, int amount,vector<int>&dp){
        if(amount == 0)
        return 0;
        if(amount<0)
        return INT_MAX;
        if(dp[amount]!=-1)
        return dp[amount];
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
           int subAns=solveMem(coins,amount-coins[i],dp);
           if(subAns!=INT_MAX)
           ans=min(ans,1+subAns);
        }
        dp[amount]=ans;
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // int ans= solveRec(coins,amount);

        // if(ans == INT_MAX)
        // return -1;
        // else
        // return ans;
        vector<int>dp(amount+1,-1);
        int ans=solveMem(coins,amount,dp);
         if(ans == INT_MAX)
        return -1;
        else
        return ans;

    }
};
