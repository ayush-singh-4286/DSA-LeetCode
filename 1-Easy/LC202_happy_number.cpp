// LeetCode Question: 202. Happy Number
// Topics: Math, Hash Table, Recursion

class Solution {
    private:
    int findHappy(int num, unordered_map<int,int>& mp){
        int n = num;
        if(n == 1)
            return 1;
        if(mp[n] == 1)
            return 0;
        mp[n] = 1;
        int square = 0;
        while(n != 0){
            int digit = n % 10;
            square += digit * digit;
            n = n / 10;
        }
        return findHappy(square, mp);
    }
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        if(findHappy(n, mp))
            return true;
        else
            return false;
    }
};
