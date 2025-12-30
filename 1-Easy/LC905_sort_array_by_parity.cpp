// LeetCode 905 - Sort Array By Parity
// Topics: Array, Two Pointers, Sorting

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        int k = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] % 2 == 0){
                ans[k] = arr[i];
                k++;
            }
        }

        for(int i = 0; i < n; i++){
            if(arr[i] % 2 != 0){
                ans[k++] = arr[i];
            }
        }

        return ans;
    }
};
