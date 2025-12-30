// LeetCode Question: 12 - Integer to Roman
// Topics: Math, Greedy, Hash Table

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> vals = {
            {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"},
            {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"},
            {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"}
        };
        string res;
        for (auto &p : vals) {
            int v = p.first;
            const string &s = p.second;
            if (num == 0) break;
            int count = num / v;
            num %= v;
            for (int i = 0; i < count; ++i) res += s;
        }
        return res;
    }
};
