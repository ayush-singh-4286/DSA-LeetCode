// LeetCode Question 13: Roman to Integer
// Topics: String, HashMap, Greedy, Math

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman;
        int n = s.size();
      
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int count = 0;
        for(int i = 0; i < n; i++){
            if(i < n-1 && roman[s[i]] < roman[s[i+1]])
                count -= roman[s[i]];
            else
                count += roman[s[i]];
        }

        return count;
    }
};
