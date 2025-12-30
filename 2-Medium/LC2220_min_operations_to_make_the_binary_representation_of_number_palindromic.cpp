// LeetCode 2220 - Minimum Operations to Make the Binary Representation of a Number Palindromic
// Topics: Math, String, Simulation, Binary

class Solution {
private:
    string convertBinary(int num){
        string s = "";
        while(num > 0){
            s.push_back((num % 2) + '0');
            num = num / 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    bool checkPal(string s){
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            int minOp = INT_MAX;
            for(int j = 0; j <= 5000; j++){
                if(x - j >= 1){
                    string s = convertBinary(x - j);
                    if(checkPal(s)){
                        minOp = j;
                        break;
                    }
                }
                string s = convertBinary(x + j);
                if(checkPal(s)){
                    minOp = j;
                    break;
                }
            }
            ans.push_back(minOp);
        }
        return ans;
    }
};
