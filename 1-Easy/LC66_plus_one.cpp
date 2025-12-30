// LeetCode Question: 66. Plus One
// Topics: Array, Math, Simulation

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i = n - 1; i >= 0; i--){
            int sum = carry;
            sum += digits[i];
            carry = sum / 10;
            sum = sum % 10;
            digits[i] = sum;
        }
        if(carry == 1)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
