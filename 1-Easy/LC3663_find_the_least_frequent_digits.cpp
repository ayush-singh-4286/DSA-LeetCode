// LeetCode Question 3663: Least Frequent Digit
// Topics: Frequency Count, Math, Arrays

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int>freq(10,0);

        while(n>0){
            int digit = n % 10;
            freq[digit]++;
            n = n / 10;
        }

        int ans = -1;
        int minFreq = INT_MAX;
        for(int i = 0; i <= 9; i++){
            if(freq[i] > 0){
                if(freq[i] < minFreq){
                    minFreq = freq[i];
                    ans = i;
                }
            }
        }
        return ans;
    }
};
