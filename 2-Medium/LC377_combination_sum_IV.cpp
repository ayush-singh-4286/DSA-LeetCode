// LeetCode Question: 377 - Combination Sum IV
// Topics: Dynamic Programming, Recursion, Memoization, Tabulation, Combinatorics

class Solution {
    private:
    int solveRec(vector<int> &num, int tar){
        // Base case
        if(tar < 0)
        return 0;
        if(tar == 0)
        return 1;
        // Ans represents number of ways to form target
        int ans=0;
        for(int i=0;i<num.size();i++){
            ans+=solveRec(num,tar-num[i]);
        }
        return ans;
    }
    int solveMem(vector<int> &num, int tar,vector<int>&dp){
        // Base case
        if(tar < 0)
        return 0;
        if(tar == 0)
        return 1;
        if(dp[tar]!=-1)
        return dp[tar];
        // Ans represents number of ways to form target
        int ans=0;
        for(int i=0;i<num.size();i++){
            ans+=solveMem(num,tar-num[i],dp);
        }
        dp[tar]=ans;
        return dp[tar];
    }
    int solveTab(vector<int> &num, int tar){
       vector<int>dp(tar+1,0);
       dp[0]=1;
       // Traversing on dp array
       for(int i=0;i<=tar;i++){
            // Traversing on num array
            for(int j=0;j<num.size();j++)
            {
                if(i-num[j] >=0)
                dp[i]+=dp[i-num[j]];
            }
       }
       return dp[tar];
    }
public:
    int combinationSum4(vector<int>& num, int tar) {
      //return solveRec(num,tar);
      vector<int>dp(tar+1,-1);
      return solveMem(num,tar,dp);
      //return solveTab(num,tar);  
    }
};
