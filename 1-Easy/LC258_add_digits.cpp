// LeetCode Question: 258. Add Digits
// Topics: Math, Recursion, Digital Root

class Solution {
    private:
    int add(int num){
        int ans = 0;
        int n = num;
        if(n >= 0 && n <= 9)
            return n;
        while(n != 0){
            int digit = n % 10;
            n = n / 10;
            ans += digit;
        }
        return add(ans);
    }
public:
    int addDigits(int num) {
        if(num >= 0 && num <= 9)
            return num;

        return add(num);
    }
};
