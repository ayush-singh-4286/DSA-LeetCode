// LeetCode 2574 - Left and Right Sum Differences
// Topics: Array, Prefix Sum

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int ps = 0;
        for(int i = 0; i < n; i++){
            ps += nums[i];
        }

        int ls = 0;
        for(int i = 0; i < n; i++){
            ps = ps - nums[i];
            int temp = abs(ps - ls);
            ls += nums[i];
            ans[i] = temp;
        }
        return ans;
    }
};
