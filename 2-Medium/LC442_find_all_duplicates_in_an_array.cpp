// LeetCode Question: 442. Find All Duplicates in an Array
// Topics: Array, Cyclic Sort, In-place Modification

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        // Place each number at its correct index
        for(int i = 0; i < n; i++){
            while((nums[i] > 0 && nums[i] <= n) && (nums[nums[i]-1] != nums[i]))
                swap(nums[i], nums[nums[i]-1]);
        }
        
        // Check which indices do not have the correct number → duplicates
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1)
                ans.push_back(nums[i]);
        }
        
        return ans;
    }
};
