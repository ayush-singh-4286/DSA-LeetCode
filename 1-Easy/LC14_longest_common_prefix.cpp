// LeetCode 14 - Longest Common Prefix
// Topics: String, Array

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0)
            return "";
        
        for(int i = 0; i < strs[0].size(); i++){
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(i >= strs[j].size() || ch != strs[j][i])
                    return ans;
            }
            ans.push_back(ch);
        }
        return ans;
    }
};
