// LeetCode Question: 27. Remove Element
// Topics: Array, Two Pointers, In-place modification

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0; // Pointer for the position to place non-val elements
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val) {
                nums[ans] = nums[i]; // Place element at the next position
                ans++;
            }
        }
        return ans; // Length of array without the value 'val'
    }
};
