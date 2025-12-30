// LeetCode Question: 643. Maximum Average Subarray I
// Topics: Array, Sliding Window

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current = 0;
        int n = nums.size();

        // sum of first window
        for(int i = 0; i < k; i++){
            current += nums[i];
        }

        double maxi = current / k;

        // slide the window
        for(int i = 1; i <= n - k; i++){
            current = current - nums[i - 1] + nums[i + k - 1];
            maxi = max(maxi, current / k);
        }

        return maxi;
    }
};
