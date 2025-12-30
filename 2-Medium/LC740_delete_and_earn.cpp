// LeetCode Question: 740 - Delete and Earn
// Topics: Dynamic Programming, Memoization, Transform to House Robber Problem

class Solution {
private:
    int recFunction(vector<int>& points, int i){
        if(i == 0)
            return 0;
        if(i < 0)
            return 0;
        int inc = recFunction(points, i-2) + points[i];
        int exclude = recFunction(points, i-1) + 0;

        return max(inc, exclude);
    }

    int memFunction(vector<int>& points, int i, vector<int>& dp){
        if(i == 0)
            return 0;
        if(i < 0)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int inc = memFunction(points, i-2, dp) + points[i];
        int exclude = memFunction(points, i-1, dp) + 0;

        dp[i] = max(inc, exclude);
        return dp[i];
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxNum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            if(nums[i] > maxNum)
                maxNum = nums[i];
        }

        vector<int> points(maxNum + 1);
        for(int i = 0; i < points.size(); i++)
            points[i] = i * (mp[i]);

        int n = points.size() - 1;
        // return recFunction(points, points.size() - 1);
        vector<int> dp(n + 1, -1);
        return memFunction(points, n, dp);
    }
};
