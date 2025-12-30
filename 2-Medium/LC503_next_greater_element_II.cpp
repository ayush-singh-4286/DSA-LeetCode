// LeetCode 503 - Next Greater Element II
// Topics: Array, Stack, Monotonic Stack, Circular Array

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < 2*n; i++){
            int j = i % n;
            while(!st.empty() && nums[j] > nums[st.top()]){
                ans[st.top()] = nums[j];
                st.pop();
            }
            if(i < n) st.push(j); 
        }
        return ans;
    }
};
