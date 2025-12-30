// LeetCode Question 378: Kth Smallest Element in a Sorted Matrix
// Topics: Binary Search, Matrix, Counting

class Solution {
private:
    int countNumber(vector<vector<int>>& matrix, int mid, int n){
        int row = n - 1;
        int col = 0;
        int count = 0;
        while(row >= 0 && col < n){
            if(matrix[row][col] <= mid){
                count += (row + 1);
                col++;
            }
            else
                row--;
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int s = matrix[0][0];
        int e = matrix[n-1][n-1];

        while(s <= e){
            int mid = s + (e - s) / 2;
            int count = countNumber(matrix, mid, n);

            if(count < k){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return s;
    }
};
