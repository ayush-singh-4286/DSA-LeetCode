// LeetCode 1025 - Divisor Game
// Topics: Math, Dynamic Programming, Game Theory

class Solution {
public:
    bool divisorGame(int n) {
        if(n % 2 == 0)
            return true;
        else
            return false;
    }
};
