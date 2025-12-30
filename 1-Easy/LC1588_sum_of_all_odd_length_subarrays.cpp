// LeetCode 1588 - Sum of All Odd Length Subarrays
// Topics: Array, Prefix Sum

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> ps(n + 1, 0);

        // prefix sum
        for(int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + arr[i];
        }

        int sum = 0;

        // odd lengths
        for(int len = 1; len <= n; len += 2) {
            for(int i = 0; i + len <= n; i++) {
                sum += ps[i + len] - ps[i];
            }
        }
        return sum;
    }
};
