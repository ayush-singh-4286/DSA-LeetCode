// LeetCode Question 84: Largest Rectangle in Histogram
// Topics: Stack, Monotonic Stack, Histogram, Next/Previous Smaller Element

#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--) {
            while(s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            while(s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);
        int area = INT_MIN;

        for(int i = 0; i < n; i++) {
            int height = heights[i];
            if(next[i] == -1) next[i] = n;
            int width = next[i] - prev[i] - 1;
            int newArea = height * width;
            area = max(area, newArea);
        }
        return area;
    }
};
