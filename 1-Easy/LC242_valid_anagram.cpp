// LeetCode Question: 242. Valid Anagram
// Topics: Hash Table, String

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m)
            return false;

        unordered_map<char,int> mp;

        // Count frequency of characters in s
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }

        // Check characters in t against the map
        for(int i = 0; i < m; i++){
            if(mp[t[i]] == 0)
                return false;
            mp[t[i]]--;
        }

        return true;
    }
};
