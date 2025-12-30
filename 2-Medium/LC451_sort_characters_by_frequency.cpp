// LeetCode Question: 451. Sort Characters By Frequency
// Topics: String, Hash Map, Heap / Priority Queue, Greedy

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;

        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;

        for(auto &it : mp)
            pq.push({it.second, it.first});

        string ans = "";
        while(!pq.empty()) {
            pair<int,char> top = pq.top();
            pq.pop();
            ans += string(top.first, top.second);
        }
        return ans;
    }
};
