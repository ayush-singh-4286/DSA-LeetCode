// LeetCode Question: 26. Remove Duplicates from Sorted Array
// Topics: Array, Hashing, Two Pointers

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> Unique;
        unordered_map<int,int> m;
        
        // Collect unique elements
        for(int i = 0; i < nums.size(); i++){
            if(m[nums[i]] == 0){
                Unique.push_back(nums[i]);
            }
            m[nums[i]]++;
        }

        // Copy unique elements back to original array
        for(int i = 0; i < Unique.size(); i++){
            nums[i] = Unique[i];
        }

        return Unique.size(); // Length of unique elements
    }
};
