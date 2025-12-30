// LeetCode Question: 128 - Longest Consecutive Sequence
// Topics: Array, Hashing, Set, Consecutive Elements

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxCount = 0;
        int count = 0;
        vector<int> arr(s.begin(), s.end());

        for(int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            // Start counting only if num-1 is not in the set
            if(s.find(num - 1) == s.end()) {
                int currentNum = num;
                count = 1;

                while(s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    count++;
                }
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};
