// LeetCode Question: 221. Maximal Square  
// Topics: Dynamic Programming, Matrix DP, Tabulation, Space Optimization

class Solution {
private:
    int solveMem(vector<vector<char>>& mat, int i, int j, int &maxi, vector<vector<int>>& dp) {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solveMem(mat, i, j + 1, maxi, dp);
        int diagonal = solveMem(mat, i + 1, j + 1, maxi, dp);
        int down = solveMem(mat, i + 1, j, maxi, dp);

        if (mat[i][j] == '1') {
            dp[i][j] = 1 + min({right, diagonal, down});
            maxi = max(maxi, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }

        return dp[i][j];
    }

    int solveTab(vector<vector<char>>& mat, int &maxi) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (mat[i][j] == '1') {
                    if (i == row - 1 || j == col - 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 1 + min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]});

                    maxi = max(maxi, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxi;
    }

    int solveSO(vector<vector<char>>& mat, int &maxi) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> curr(col + 1, 0);
        vector<int> next(col + 1, 0);

        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (mat[i][j] == '1') {
                    curr[j] = 1 + min({curr[j + 1], next[j], next[j + 1]});
                    maxi = max(maxi, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return maxi;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        solveSO(matrix, maxi);
        return maxi * maxi;
    }
};
