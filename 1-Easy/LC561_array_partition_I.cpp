// LeetCode 561 - Array Partition I
// Topics: Array, Sorting, Greedy

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mini = 0;
        int n = nums.size();
        for(int i = 0; i < n-1; i = i + 2){
            mini += min(nums[i], nums[i+1]);
        }
        return mini;
    }
};
