// LeetCode Question 1009: Complement of Base 10 Integer
// Topics: Bit Manipulation, Number Theory

class Solution {
public:
    int bitwiseComplement(int n) {
        int m = n;
        if(n == 0)
            return 1;

        int mask = 0;
        while(m != 0) {
            mask = (mask << 1) | 1; // create mask with all bits as 1 for n's length
            m = m >> 1;
        }

        int ans = (~n) & mask; // flip bits and mask
        return ans;
    }
};
