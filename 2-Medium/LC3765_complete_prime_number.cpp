// LeetCode 3765 - Complete Prime Number Check
// Topics: Math, String, Prime Checking, Simulation

class Solution {
    bool checkPrime(int n){
        if(n <= 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;

        for(int i = 3; i * i <= n; i += 2){
            if(n % i == 0) return false;
        }
        return true;
    }

public:
    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        // Check prefixes
        for(int i = 1; i <= n; i++){
            int prefix = stoi(s.substr(0, i));
            if(!checkPrime(prefix)) return false;
        }

        // Check suffixes
        for(int i = 0; i < n; i++){
            int suffix = stoi(s.substr(i));
            if(!checkPrime(suffix)) return false;
        }

        return true;
    }
};
