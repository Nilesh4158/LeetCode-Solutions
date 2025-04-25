class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        // Initialize the starting cell
        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        if (dp[0][0] == 0) return 0;
        
        // Fill the first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j-1];
            } else {
                dp[0][j] = 0;
            }
        }
        
        // Fill the first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];
            } else {
                dp[i][0] = 0;
            }
        }
        
        // Fill the rest of the table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};