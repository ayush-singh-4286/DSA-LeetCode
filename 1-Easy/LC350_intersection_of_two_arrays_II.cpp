// LeetCode Question: 350 - Intersection of Two Arrays II
// Topics: Hash Map, Array, Frequency Count, Two Pointers (optional), Sorting (optional)

class Solution {
    private:
    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     sort(nums1.begin(),nums1.end());
    //      sort(nums2.begin(),nums2.end());
    //         vector<int>ans;
    //         int i=0,j=0;
    //         while(i<nums1.size() && j<nums2.size()){
    //             if(nums1[i] == nums2[j]){
    //                 ans.push_back(nums1[i]);
    //                 i++;
    //                 j++;
    //             }
    //             else if(nums1[i] > nums2[j])
    //             j++;
    //             else
    //             i++;
    //         }
    //         return ans;
    // }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;// freq elements
        for(int num:nums1)
            mp[num]++;
        vector<int>ans;
        for(int num:nums2){
            if(mp[num]>0){
                ans.push_back(num);
                mp[num]--;
            }
        }
        return ans;
    }
};
