// LeetCode Question: 283 - Move Zeroes
// Topics: Array, Two Pointers, In-place Modification

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // points to the position to place the next non-zero element
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
