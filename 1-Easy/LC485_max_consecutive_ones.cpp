// LeetCode Question: 485 - Max Consecutive Ones
// Topics: Array, Counting, Sliding Window

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int tempCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                tempCount++;
                count = max(count, tempCount);
            }
            else
                tempCount = 0;
        }
        return count;
    }
};
