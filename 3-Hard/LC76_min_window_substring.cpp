// LeetCode 76 - Minimum Window Substring
// Topics: Two Pointers, Sliding Window, Hash Table, String

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        string ans = "";
        if (n > m) return ans;
        
        unordered_map<char,int> map2;
        for (int i = 0; i < n; i++)
            map2[t[i]]++;
        
        unordered_map<char,int> map1;
        int i = 0, j = 0;
        
        int required = map2.size();
        int formed = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (j < m) {
            map1[s[j]]++;

            if (map2.count(s[j]) && map1[s[j]] == map2[s[j]])
                formed++;

            while (formed == required) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                char left = s[i];
                map1[left]--;

                if (map2.count(left) && map1[left] < map2[left])
                    formed--;

                i++;
            }

            j++;
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};
