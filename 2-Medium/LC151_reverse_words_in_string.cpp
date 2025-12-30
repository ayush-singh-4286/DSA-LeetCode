// LeetCode 151 - Reverse Words in a String
// Topics: String, Two Pointers

class Solution {
private:
    void reverseRange(string &s, int i, int j) {
        while(i < j) {
            swap(s[i], s[j]);
            i++; j--;
        }
    }

    void reverseWord(string &s, string &ans, int i, int j) {

        // 1. reverse the word inside s
        int left = i;
        int right = j;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }

        // 2. copy reversed word into ans
        for(int x = i; x <= j; x++){
            ans.push_back(s[x]);
        }
        ans.push_back(' '); // add space between words
    }

public:
    string reverseWords(string s) {

        int n = s.size();
        string ans = "";

        int i = 0;

        // skip leading spaces
        while(i < n && s[i] == ' ')
            i++;

        while(i < n) {

            int j = i;

            // move j to end of word
            while(j < n && s[j] != ' ')
                j++;

            // reverse this word and append to ans
            reverseWord(s, ans, i, j-1);

            // skip spaces between words
            while(j < n && s[j] == ' ')
                j++;

            i = j;
        }

        // remove last extra space
        if(ans.size() > 0 && ans.back() == ' ')
            ans.pop_back();

        // reverse whole ans to get final order
        reverseRange(ans, 0, ans.size()-1);

        return ans;
    }
};
