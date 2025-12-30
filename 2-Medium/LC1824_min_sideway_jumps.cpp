// LeetCode 1824 - Minimum Sideway Jumps
// Topics: Array, Dynamic Programming, Recursion

class Solution {
private:
    int solveRec(vector<int>& obstacles, int currLane, int currPos) {
        int n = obstacles.size();
        if(currPos == n-1)
            return 0;
        // this condition means no obstacle is present on currLane
        if(obstacles[currPos+1] != currLane){
            return solveRec(obstacles, currLane, currPos+1);
        } else {
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++){
                if(currLane != i && obstacles[currPos] != i){
                    ans = min(ans, 1 + solveRec(obstacles, i, currPos));
                }
            }
            return ans;
        }
    }

    int solveMem(vector<int>& obstacles, int currLane, int currPos, vector<vector<int>>& dp) {
        int n = obstacles.size();
        if(currPos == n-1)
            return 0;
        // this condition means no obstacle is present on currLane
        if(dp[currLane][currPos] != -1)
            return dp[currLane][currPos];

        if(obstacles[currPos+1] != currLane){
            return solveMem(obstacles, currLane, currPos+1, dp);
        } else {
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++){
                if(currLane != i && obstacles[currPos] != i){
                    ans = min(ans, 1 + solveMem(obstacles, i, currPos, dp));
                }
            }
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        // return solveRec(obstacles, 2, 0);  
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        return solveMem(obstacles, 2, 0, dp);
    }
};
