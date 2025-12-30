// LeetCode 191 — Number of 1 Bits
// Topic: Bit Manipulation

class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        while(n!=0){
            int i=0;
            i=n&1;
            n=n>>1;
            ans =ans+i;
        }
        return ans;
    }
};
