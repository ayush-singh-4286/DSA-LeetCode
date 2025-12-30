// LeetCode 239 - Sliding Window Maximum
// Topics: Sliding Window, Deque, Array

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores INDEXES
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            // 1️⃣ Remove out-of-window index (front)
            if(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // 2️⃣ Remove all smaller values from BACK
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // 3️⃣ Insert current index
            dq.push_back(i);

            // 4️⃣ When window size becomes k → record answer
            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
