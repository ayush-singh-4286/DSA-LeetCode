// LeetCode 1991 - Find the Middle Index in Array
// Topics: Array, Prefix Sum

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int ps = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ps += nums[i];
        }

        int ls = 0;
        for(int i = 0; i < n; i++){
            ps = ps - nums[i];
            if(ps == ls)
                return i;
            else
                ls += nums[i];
        }
        return -1;
    }
};
