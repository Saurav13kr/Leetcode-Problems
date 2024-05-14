class Solution {
public:
    int solve(int r,int c,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        vis[r][c]=1;
        int a=INT_MIN,b=INT_MIN,cc=INT_MIN,d=INT_MIN;
        if(r+1<n && grid[r+1][c]!=0 && vis[r+1][c]==0)
        {
            vis[r+1][c]=1;
            a=grid[r][c]+solve(r+1,c,n,m,grid,vis); 
            vis[r+1][c]=0;   
        }
        if(c+1<m && grid[r][c+1]!=0 && vis[r][c+1]==0)
        {
            vis[r][c+1]=1;
            b=grid[r][c]+solve(r,c+1,n,m,grid,vis);
            vis[r][c+1]=0;    
        }
        if(r-1>=0 && grid[r-1][c]!=0 && vis[r-1][c]==0)
        {
            vis[r-1][c]=1;
            cc=grid[r][c]+solve(r-1,c,n,m,grid,vis);
            vis[r-1][c]=0;    
        }
        if(c-1>=0 && grid[r][c-1]!=0 && vis[r][c-1]==0)
        {
            vis[r][c-1]=1;
            d=grid[r][c]+solve(r,c-1,n,m,grid,vis);
            vis[r][c-1]=0;    
        }

        int ans=max(a,max(b,max(cc,d)));
        if(ans==INT_MIN){
            return grid[r][c];
        }
        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<vector<int>> vis(n,vector<int>(m,0));
                if(grid[i][j]!=0)
                {
                    ans=max(solve(i,j,n,m,grid,vis),ans);
                }
            }
        }

        return ans;
    }
};