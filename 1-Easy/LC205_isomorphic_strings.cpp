// LeetCode Question: 205. Isomorphic Strings
// Topics: Hash Map, String, One-to-One Mapping

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> m;
        int n = s.size();
        int x = t.size();
        bool isFlag = true;
        if(n != x)
            return false;

        int i = 0, j = 0;
        while(i < n){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[j]){
                    isFlag = false;
                    break;
                }
            }
            else{
                mp[s[i]] = t[j];
            }

            if(m.find(t[j]) != m.end()){
                if(m[t[j]] != s[i]){
                    isFlag = false;
                    break;
                }
            }
            else{
                m[t[j]] = s[i];
            }

            i++;
            j++;
        }
        return isFlag;
    }
};
