// LeetCode Question 154: Find Minimum in Rotated Sorted Array II
// Topics: Binary Search, Array, Search

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        
        while(s < e) {
            int mid = s + (e - s) / 2;
            if(arr[mid] > arr[e])
                s = mid + 1;
            else if(arr[mid] < arr[e])
                e = mid;
            else if(arr[mid] == arr[e])
                e--;
        }
        
        return arr[s];
    }
};
