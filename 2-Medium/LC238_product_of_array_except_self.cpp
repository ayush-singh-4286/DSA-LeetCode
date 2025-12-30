// LeetCode Question 238: Product of Array Except Self
// Topics: Array, Prefix Product, Math

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int count = 0;
        int ps = 1;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                count++;
                continue;
            }
            ps = ps * nums[i];
        }
        
        for(int i = 0; i < n; i++){
            if(count > 1)
                ans[i] = 0;
            else if(count == 1){
                if(nums[i] == 0) ans[i] = ps;
                else ans[i] = 0;
            } else {
                ans[i] = ps / nums[i];
            }
        }
        
        return ans;
    }
};
