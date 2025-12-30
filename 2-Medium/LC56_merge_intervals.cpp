// LeetCode 56 - Merge Intervals
// Topics: Array, Sorting, Intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        ans.push_back(intervals[0]);
        int n = intervals.size();
        
        for(int i = 1; i < n; i++){
            // If current interval overlaps with last interval in ans
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
