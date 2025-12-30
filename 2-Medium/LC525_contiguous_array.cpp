// LeetCode 525 - Contiguous Array
// Topics: Array, Hash Table, Prefix Sum

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                nums[i] = -1;
        }

        vector<int> ps(n);
        unordered_map<int,int> mp;
        mp[0] = -1;

        ps[0] = nums[0];
        mp[ps[0]] = 0;

        for(int i = 1; i < n; i++){
            ps[i] = ps[i-1] + nums[i];
        }

        int length = 0;
        for(int i = 0; i < n; i++){
            int val = ps[i];
            
            if(mp.find(val) != mp.end()){
                int templength = i - mp[val];
                length = max(length, templength);
            } else {
                mp[val] = i;
            }
        }
        return length;
    }
};
