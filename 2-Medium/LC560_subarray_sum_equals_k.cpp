// LeetCode Question 560: Subarray Sum Equals K
// Topics: Array, Prefix Sum, Hash Map

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size());
        unordered_map<int,int> m; // prefix sum frequency
        int count = 0;

        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){ 
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }   

        for(int j = 0; j < nums.size(); j++){
            if(prefixSum[j] == k) count++;

            int val = prefixSum[j] - k;
            if(m.find(val) != m.end()) {
                count += m[val];
            }

            m[prefixSum[j]]++;
        }
        return count;
    }
};
