// LeetCode Question: 35. Search Insert Position
// Topics: Array, Binary Search

class Solution {
    private:
    int solve(vector<int>& nums, int target){
        int ans = 0;
        // Edge case condition full fill
        if(nums[0] > target)
            return 0;
        if(nums[nums.size()-1] < target)
            return nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                ans = i;
            }
            else if(i < nums.size()-1 && nums[i] < target &&
                    nums[i+1] > target){
                ans = i+1;
            }
        }
        return ans;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = solve(nums, target);
        return ans;
    }
};
