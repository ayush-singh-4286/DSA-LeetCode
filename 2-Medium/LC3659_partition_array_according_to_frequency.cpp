// LeetCode Question 3664: Partition Array According to Frequency
// Topics: Arrays, Hash Map, Frequency Count, Math

class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        // Step1-We check size of array is divisible by given k or not
        if(n % k != 0)
            return false;
        unordered_map<int,int> m; // nums[i], freq
        for(int i = 0; i < n; i++){
            m[nums[i]] += 1;
        }
        // Step2-How many group is formed and compare with element's frequency
        int groups = n / k;
        
        for(auto &p : m){
            if(p.second > groups)
                return false;
        }
        return true;
    }
};
