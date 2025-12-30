// LeetCode Question: 796. Rotate String
// Topics: String, Brute Force, String Manipulation

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n != goal.size())
            return false;

        string temp = s + s;
        for(int i = 0; i <= temp.size() - n; i++) {
            int j = 0;
            while(j < n && temp[i + j] == goal[j])
                j++;

            if(j == n)
                return true;
        }
        return false;
    }
};
