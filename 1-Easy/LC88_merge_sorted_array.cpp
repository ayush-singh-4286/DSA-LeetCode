// LeetCode Question 88: Merge Sorted Array
// Topics: Arrays, Two Pointers, In-place Merge

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Index of last element in nums1's initial segment
        int j = n - 1;      // Index of last element in nums2
        int k = m + n - 1;  // Index of last position in nums1

        // Merge in reverse order
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
