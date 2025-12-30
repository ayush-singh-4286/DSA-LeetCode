// LeetCode Question: 189 - Rotate Array
// Topics: Array, In-place Modification, Recursion

class Solution {
private:
    void reverse(vector<int>& nums, int i, int j){
        if(i >= j) return;
        swap(nums[i], nums[j]);
        reverse(nums, i + 1, j - 1);
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // In case k > n

        // Step 1: Reverse the whole array
        reverse(nums, 0, n - 1);
        // Step 2: Reverse the first k elements
        reverse(nums, 0, k - 1);
        // Step 3: Reverse the remaining n-k elements
        reverse(nums, k, n - 1);
    }
};
