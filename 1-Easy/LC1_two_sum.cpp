// LeetCode 1 - Two Sum
// Topics: Array, Hash Table

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int val = target - nums[i];

            if(mp.find(val) != mp.end() && mp[val] != i)
            {
                ans.push_back(i);
                ans.push_back(mp[val]);
                break;
            }
        }
        return ans;
    }
};
