class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

        for (int j = grid[0].size() - 1; j >= 0; --j) {
            for (int i = grid.size() - 1; i >= 0; --i) 
            {
                
                if (i >= 1 && j < (grid[0].size() - 1) && grid[i][j] < grid[i - 1][j + 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
                }
                if (j < (grid[0].size() - 1) && grid[i][j] < grid[i][j + 1]) 
                {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
                }

                if (i < (grid.size() - 1) && j < (grid[0].size() - 1) &&
                    grid[i][j] < grid[i + 1][j + 1]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < dp.size(); ++i) {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};