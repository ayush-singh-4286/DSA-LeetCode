// LeetCode Question 4: Median of Two Sorted Arrays
// Topics: Arrays, Sorting, Merge, Median

class Solution {
private:
    void merge(vector<int> &arr1,int n,vector<int> &arr2,int m,vector<int> &arr3){
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
                arr3.push_back(arr1[i++]);
            else
                arr3.push_back(arr2[j++]);
        }

        while (i < n)
            arr3.push_back(arr1[i++]);

        while (j < m)
            arr3.push_back(arr2[j++]);
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int n = nums1.size();
        int m = nums2.size();
        merge(nums1, n, nums2, m, nums3);

        int size = nums3.size();
        double ans = 0;

        if (size % 2 == 0)
            ans = (nums3[size/2] + nums3[(size/2)-1]) / 2.0;
        else
            ans = nums3[size/2];

        return ans;
    }
};
