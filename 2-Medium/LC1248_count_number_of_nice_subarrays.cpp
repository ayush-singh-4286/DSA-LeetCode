// LeetCode Question: 1248. Count Number of Nice Subarrays
// Topics: Array, Prefix Sum, Hash Map

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Convert nums into 1 (odd) and 0 (even)
        for(int i = 0; i < n; i++){
            nums[i] = (nums[i] % 2 != 0) ? 1 : 0;
        }

        unordered_map<int,int> mp; // prefix sum frequency
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for(int i = 0; i < n; i++){
            prefixSum += nums[i];

            if(mp.find(prefixSum - k) != mp.end())
                count += mp[prefixSum - k];

            mp[prefixSum]++;
        }

        return count;
    }
};
