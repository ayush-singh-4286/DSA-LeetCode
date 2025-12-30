// LeetCode Question 33: Search in Rotated Sorted Array
// Topics: Binary Search, Array, Rotated Sorted Array

class Solution {
private:
    int binarySearch(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;

        while(s <= e){
            if(nums[mid] == target) return mid;

            if(nums[s] <= nums[mid]){ // Left part is sorted
                if(nums[s] <= target && target <= nums[mid])
                    e = mid - 1;
                else
                    s = mid + 1;
            } else { // Right part is sorted
                if(nums[mid] <= target && target <= nums[e])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target);
    }
};
