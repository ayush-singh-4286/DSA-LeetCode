// LeetCode 1695 - Maximum Erasure Value
// Topics: Array, Hash Table, Sliding Window, Prefix Sum

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> mp;
        int n = nums.size();
        int left = 0;
        int tempCount = 0;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            while(mp[nums[i]] > 1){
                tempCount -= nums[left];
                mp[nums[left]]--;
                left++;
            }

            tempCount += nums[i];
            count = max(count, tempCount);
        }
        
        return count;
    }
};
