// LeetCode 504 - Base 7
// Topics: Math, Number Conversion, Simulation

class Solution {
private:
    int convert(int num){
        int n;
        if(num < 0){
            n = -num;
        }
        else
            n = num;

        int ans = 0;
        int i = 0;
        while(n > 0){
            int digit = n % 7;
            n = n / 7;
            ans += digit * (pow(10, i));
            i++;
        }
        return ans;
    }

public:
    string convertToBase7(int num) {
        int ans = convert(num);
        if(num < 0)
            ans = -ans;
        string s = to_string(ans);
        return s;
    }
};
