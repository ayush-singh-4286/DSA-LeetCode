// LeetCode Question: 1456. Maximum Number of Vowels in a Substring of Given Length
// Topics: String, Sliding Window, Two Pointers

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int count = 0;

        // count vowels in first window
        for(int i = 0; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                count++;
        }

        int maxCount = count;

        // slide the window
        for(int i = 1; i <= n - k; i++){
            if(s[i + k - 1] == 'a' || s[i + k - 1] == 'e' || s[i + k - 1] == 'i' 
               || s[i + k - 1] == 'o' || s[i + k - 1] == 'u')
                count++;

            if(s[i - 1] == 'a' || s[i - 1] == 'e' || s[i - 1] == 'i' 
               || s[i - 1] == 'o' || s[i - 1] == 'u')
                count--;

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
