// LeetCode Question: 2149 - Rearrange Array Elements by Sign
// Topics: Array, Two Pointers, Simulation

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0)
                negative.push_back(nums[i]);
            else
                positive.push_back(nums[i]);
        }

        vector<int> ans;
        for(int i = 0; i < n / 2; i++) {
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }

        return ans;
    }
};
