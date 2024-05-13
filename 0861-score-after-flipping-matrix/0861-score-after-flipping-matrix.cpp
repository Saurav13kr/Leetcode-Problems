class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    if(grid[i][j]){
                        grid[i][j]=0;
                    }else{
                        grid[i][j]=1;
                    }
                }
            }
        }
        
        for(int j=1;j<m;j++)
        {
            int count=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]) count++;
            }
            if(2*count<n){
                for(int i=0;i<n;i++){
                    if(grid[i][j]){
                        grid[i][j]=0;
                    }else{
                        grid[i][j]=1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    temp+=(1<<(m-1-j));
                }
            }
            ans+=temp;
        }
        return ans;
    }
};