class Solution {
public:
    int h = 1e9+7;
    vector<vector<int>>dp;
    bool check(int i, int j, int m, int n) {
        if(i<0 || j<0 || i==m || j==n) return false;
        return true;
    }
    
    int f(vector<vector<int>>& grid, int i, int j, int m, int n) {
           if(dp[i][j] !=- 1) return dp[i][j];
           int a=0, b=0, c=0, d=0;

           if(check(i+1, j, m, n)) {
               if(grid[i+1][j]>grid[i][j]) {
                   a += f(grid, i+1, j, m, n) % h;
               }
           }
        
           if(check(i-1, j, m, n)) {
               if(grid[i-1] [j] > grid[i] [j]) {
                   b += f(grid, i-1, j, m, n) % h;
               }
           }
        
           if(check(i, j+1, m, n)) {
               if(grid[i][j+1] > grid[i][j]) {
                   c+=f(grid, i, j+1, m, n) % h;
               }
           }
        
           if(check(i, j-1, m, n)) {
               if(grid[i] [j-1] > grid[i] [j]) {
                   d+=f(grid, i, j-1, m, n) % h;
               }
           }


           return dp[i][j] = (1+a+b+c+d) % h;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        dp.resize(m+1, vector<int>(n+1, -1));
        int p = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(dp[i][j] !=- 1) p= (p+dp[i][j] %h) % h;
                else p = (p +f(grid, i, j, m, n) % h) % h;
            }
        }
        return p;
    }
};