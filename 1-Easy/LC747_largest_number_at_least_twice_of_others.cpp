// LeetCode Question: 747 - Largest Number At Least Twice of Others
// Topics: Array, Math, Iteration

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int index = -1;

        // Find the maximum element and its index
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                index = i;
            }
        }

        // Check if the maximum element is at least twice every other element
        for(int i = 0; i < n; i++){
            if(i == index) continue;
            if(maxi < nums[i] * 2) return -1;
        }

        return index;
    }
};
