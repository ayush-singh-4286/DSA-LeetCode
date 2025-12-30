// LeetCode Question: 983 - Minimum Cost For Tickets
// Topics: Dynamic Programming, Recursion, Memoization, Tabulation

class Solution {
    private:
    int solveRec(int n, vector<int> &days, vector<int> &cost
                ,int index){
    // Base Case
    if(index>=n)
    return 0;
    // For 1 day ticket
    int option1=cost[0]+solveRec(n,days,cost,index+1);
    // For 7 days ticket
    int i;
    for( i=index;i<n && days[i]<days[index]+7;i++);
    int option2=cost[1]+solveRec(n,days,cost,i);

    // For 30 days ticket
    for( i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solveRec(n,days,cost,i);


    return min(option1,min(option2,option3));
    
   }
   int solveMem(int n, vector<int>& days, vector<int>& cost
                ,int index,vector<int>&dp){
    // Base Case
    if(index>=n)
    return 0;
    if(dp[index]!=-1)
    return dp[index];
    // For 1 day ticket
    int option1=cost[0]+solveMem(n,days,cost,index+1,dp);
    // For 7 days ticket
    int i;
    for( i=index;i<n && days[i]<days[index]+7;i++);
    int option2=cost[1]+solveMem(n,days,cost,i,dp);

    // For 30 days ticket
    for( i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solveMem(n,days,cost,i,dp);


    dp[index]= min(option1,min(option2,option3));
    return dp[index];
   }
   int solveTab(int n,vector<int>&days,vector<int>&cost){
      vector<int>dp(n+1,INT_MAX);
      dp[n]=0;
      for(int k=n-1;k>=0;k--){
   int option1=cost[0]+dp[k+1];
    // For 7 days ticket
    int i;
    for( i=k;i<n && days[i]<days[k]+7;i++);
    int option2=cost[1]+dp[i];

    // For 30 days ticket
    for( i=k;i<n && days[i]<days[k]+30;i++);
    int option3=cost[2]+dp[i];
   dp[k]=min(option1,min(option2,option3));
      }
      
      return dp[0];
   }

public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        return solveTab(days.size(),days,cost);
    }
};
