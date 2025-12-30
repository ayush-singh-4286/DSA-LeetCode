// LeetCode Question 34: Find First and Last Position of Element in Sorted Array
// Topics: Binary Search, Arrays, Search

#include <vector>
using namespace std;

class Solution {
public:
    int firstOcc(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == target) {
                ans = mid;
                e = mid - 1;  // Keep searching on the left side
            }
            else if (arr[mid] > target) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }

    int lastOcc(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == target) {
                ans = mid;
                s = mid + 1;  // Keep searching on the right side
            }
            else if (arr[mid] > target) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums, target);
        int last = lastOcc(nums, target);
        return {first, last};
    }
};
