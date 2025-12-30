// LeetCode 2090 - K Radius Subarray Averages
// Topics: Array, Sliding Window, Prefix Sum

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        if (2*k + 1 > n) return ans;

        long long windowSum = 0;

        // first window
        for (int i = 0; i <= 2*k; i++)
            windowSum += nums[i];

        int center = k;
        ans[center] = windowSum / (2*k + 1);

        // slide window
        for (int i = 2*k + 1; i < n; i++) {
            windowSum += nums[i];
            windowSum -= nums[i - (2*k + 1)];
            center++;
            ans[center] = windowSum / (2*k + 1);
        }

        return ans;
    }
};
