class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int steps = 0;
        queue<pair<pair<int,int>,int>> q; 
        vector<int> delrow{0, -1, 0, 1};
        vector<int> delcol{-1, 0, 1, 0};
        q.push({{entrance[0],entrance[1]},steps});
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(maze[i][j] == '+')
                vis[i][j] = 1;
            }
        }

        vis[entrance[0]][entrance[1]] = 1;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];                
                if(nrow<m && nrow >= 0 && ncol<n && ncol>=0 && 
                maze[nrow][ncol]=='.' && !vis[nrow][ncol]){

                    if(nrow == 0 || nrow == m-1 || ncol == 0 || ncol == n-1)
                    return steps + 1;
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps+1});
                }
            } 
        }
        return -1;
    }
};