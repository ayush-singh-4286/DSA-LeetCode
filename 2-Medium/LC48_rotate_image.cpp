// LeetCode Question 48: Rotate Image
// Topics: Matrix, In-place, Array Manipulation

class Solution {
private:
    void transpose(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[j][i], matrix[i][j]);
            }
        }
    }

    void swapMatrix(vector<vector<int>>& matrix){
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        swapMatrix(matrix);
    }
};
