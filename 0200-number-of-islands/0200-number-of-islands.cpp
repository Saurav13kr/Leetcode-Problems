int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c,int n, int m){
        grid[r][c]='2';
        for(int i=0;i<4;i++){
            int row=r+dx[i];
            int col=c+dy[i];
            if(row>=0 && row<n && col>=0 && col<m && grid[row][col]=='1')
               dfs(grid,row,col,n,m);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]=='1'){
                    islands++;
                    dfs(grid,r,c,n,m);
                }
            }
        }
        return islands;
    }
};