/*
class Solution {
public:

    int solve(vector<vector<int>>& matrix, int i, int j,
              vector<vector<int>>& dp) {

        int n = matrix.size();

        // Out of bounds
        if (j < 0 || j >= n) {
            return 1e9;
        }

        // First row
        if (i == 0) {
            return matrix[i][j];
        }

        // Already calculated
        if (dp[i][j] != 1e9) {
            return dp[i][j];
        }

        // Up
        int up = solve(matrix, i - 1, j, dp);

        // Left diagonal
        int left = solve(matrix, i - 1, j - 1, dp);

        // Right diagonal
        int right = solve(matrix, i - 1, j + 1, dp);

        return dp[i][j] = matrix[i][j] + min({up, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        int ans = 1e9;

        // Start from last row
        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(matrix, n - 1, j, dp));
        }

        return ans;
    }
};

*/