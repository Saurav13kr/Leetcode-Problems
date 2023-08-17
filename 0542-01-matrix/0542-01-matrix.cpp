class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> s(m,vector<int>(n,0)); 
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        vector<int> dx={0,1,0,-1};
        vector<int> dy={1,0,-1,0};

        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            s[x][y]=q.front().second;
            int d=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int v=x+dx[i];
                int z=y+dy[i];
                
                if(v>=0 && v<m
                && z>=0 && z<n
                   
                && vis[v][z]==0 && mat[v][z]==1){
                    q.push({{v,z},d+1});
                    vis[v][z]=1;
                }
            }

        }
        return s; 
    }
};