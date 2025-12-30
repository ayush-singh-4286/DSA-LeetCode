// LeetCode Question: 67. Add Binary
// Topics: String, Binary Addition, Simulation

class Solution {
private:
    string add(string &a, string &b){
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans = "";
        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0)
                sum += a[i] - '0';
            if(j >= 0)
                sum += b[j] - '0';

            carry = sum / 2;
            sum = sum % 2;

            ans += (sum + '0');
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string addBinary(string a, string b) {
        return add(a, b);
    }
};
