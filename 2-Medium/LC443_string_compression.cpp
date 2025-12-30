// LeetCode 443 - String Compression
// Topics: Array, Two Pointers, String, Simulation

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;  // jaha pe output likhenge
        int i = 0;      // array ko read karne ka pointer
        
        while (i < chars.size()) {
            char ch = chars[i];  // current character
            int count = 0;

            // count same characters
            while (i < chars.size() && chars[i] == ch) {
                i++;
                count++;
            }

            // write character
            chars[write++] = ch;

            // write count only if > 1
            if (count > 1) {
                string s = to_string(count);
                for (char c : s) {
                    chars[write++] = c;
                }
            }
        }

        return write;  // final compressed length
    }
};
