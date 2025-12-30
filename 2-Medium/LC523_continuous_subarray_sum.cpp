// LeetCode Question 523: Continuous Subarray Sum
// Topics: Array, Prefix Sum, HashMap, Modulo

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m; // remainder -> first occurrence index
        m[0] = -1; // for edge case where sum from start is multiple of k
        int n = nums.size();
        int ps = 0; // prefix sum
        
        for(int i = 0; i < n; i++){
            ps += nums[i];
            int rem = ps % k;
            
            if(m.find(rem) != m.end()){
                if(i - m[rem] >= 2) // subarray length >= 2
                    return true;
            } else {
                m[rem] = i; // store first occurrence of this remainder
            }
        }
        return false;
    }
};

