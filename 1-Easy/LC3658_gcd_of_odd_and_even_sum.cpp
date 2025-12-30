// LeetCode Question 3665: GCD of Odd and Even Sums
// Topics: Math, GCD, Number Theory

class Solution {
    private:
    int gcd(int a,int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * n;
        int sumEven = n * (n + 1);
        
        return gcd(sumOdd, sumEven);
    }
};
