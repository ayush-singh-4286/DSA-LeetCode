// LeetCode 73 - Set Matrix Zeroes
// Topics: Array, Matrix, Simulation, Hashing

class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        vector<vector<int>> ans = arr;
        int row = arr.size();
        int col = arr[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(arr[i][j] == 0){
                    int x = i;
                    int y = j;

                    while(x >= 0){
                        ans[x][j] = 0;
                        x--;
                    }
                    x = i;
                    while(x < row){
                        ans[x][j] = 0;
                        x++;
                    }

                    while(y >= 0){
                        ans[i][y] = 0;
                        y--;
                    }
                    y = j;
                    while(y < col){
                        ans[i][y] = 0;
                        y++;
                    }
                }
            }
        }

        arr = ans;
    }
};
