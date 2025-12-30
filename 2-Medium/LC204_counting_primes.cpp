// LeetCode 204 — Count Primes
// Topic: Sieve of Eratosthenes, Math

class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;

                for(int k=2*i;k<n;k=k+i){
                    prime[k]=0;
                }
            }
        }
        return count;
    }
};
