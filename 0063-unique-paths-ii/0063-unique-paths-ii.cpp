class Solution {
public:
    int f(int i,int j,vector<vector<int>> &dp,vector<vector<int>>& grid){
        if(i==0 && j==0) 
            return 1;
        if(i<0||j<0||grid[i][j]==1) 
            return 0;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        int up=f(i-1,j,dp,grid);
        int left=f(i,j-1,dp,grid);
        return dp[i][j]=up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0]==1||grid[n-1][m-1]==1) 
            return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,grid); 
    }
};