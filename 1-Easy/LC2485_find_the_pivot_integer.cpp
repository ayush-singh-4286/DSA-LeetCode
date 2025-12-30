// LeetCode 2485 - Find the Pivot Integer
// Topics: Math, Prefix Sum

class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i;
        }

        int ls = 0;
        for(int i = 1; i <= n; i++){
            ls += i;
            if(sum == ls)
                return i;
            sum -= i;
        }
        return -1;
    }
};
