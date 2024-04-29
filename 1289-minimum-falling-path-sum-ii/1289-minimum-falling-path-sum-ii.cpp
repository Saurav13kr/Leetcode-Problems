class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
      int N=grid.size();
      vector<vector<int>> dp(N,vector<int>(N,0));
        
      for(int i=0;i<N;++i){
        dp[0][i]=grid[0][i];
      }
        
      for(int i=1;i<N;++i){
        for(int j=0;j<N;++j){
          int cost=INT_MAX;
          for(int k=0;k<N;++k){
            if(k==j)
              continue;
            cost=min(cost,dp[i-1][k]+grid[i][j]);
          }
          dp[i][j]=cost;
        }
      }
      return *ranges::min_element(dp.back());
    }
};