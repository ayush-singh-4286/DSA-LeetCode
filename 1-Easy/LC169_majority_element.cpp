// LeetCode 169 - Majority Element
// Topics: Array, Hash Table, Counting

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> countMaj;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            countMaj[nums[i]]++;
        }

        int mini = 0;
        int maxi = INT_MIN;

        for(auto i : countMaj){
            if(maxi < i.second){
                maxi = i.second;
                mini = i.first;
            }
        }

        return mini;
    }
};
