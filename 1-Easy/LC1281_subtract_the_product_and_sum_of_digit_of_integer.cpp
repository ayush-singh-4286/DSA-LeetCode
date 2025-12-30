// LeetCode 1281 - Subtract the Product and Sum of Digits of an Integer
// Topics: Math, Number, Simulation

class Solution {
    int product(int n){
        int x = n;
        int ans = 1;
        while(x > 0){
            int digit = x % 10;
            ans *= digit;
            x = x / 10;
        }
        return ans;
    }

    int add(int n){
        int x = n;
        int ans = 0;
        while(x > 0){
            int digit = x % 10;
            ans += digit;
            x = x / 10;
        }
        return ans;
    }

public:
    int subtractProductAndSum(int n) {
        int pro = product(n);
        int sum = add(n);
        return pro - sum;
    }
};
