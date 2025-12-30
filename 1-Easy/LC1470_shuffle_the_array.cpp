// LeetCode 1470 - Shuffle the Array
// Topics: Array, Simulation, Two Pointers

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int m = 2 * n;
        vector<int> ans(m);

        int i = 0;
        int j = n;
        int k = 0;
        while(i < n && j < m){
            ans[k++] = nums[i++];
            ans[k++] = nums[j++];
        }
        return ans;
    }
};
