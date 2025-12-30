// LeetCode Question: 974. Subarray Sums Divisible by K
// Topics: Array, Prefix Sum, Hash Map

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum = 0, rem = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;

        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            rem = ((prefixSum % k) + k) % k;

            if(mp.count(rem))
                count += mp[rem];

            mp[rem]++;
        }
        return count;
    }
};
