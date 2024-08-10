class Solution {
    void dfs(int i, int j, vector<vector<bool>> &visited) {
        if(i < 0 || j < 0 || i >= visited.size() || j >= visited.size() || visited[i][j]) return;
        visited[i][j] = true;
        dfs(i - 1, j, visited);
        dfs(i + 1, j, visited);
        dfs(i, j - 1, visited);
        dfs(i, j + 1, visited);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(3 * n, vector<bool>(3 * n)); 
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                int bI = 3 * i, bJ = 3 * j;
                for(int k = 0; k < 3; k++) 
                {
                    if(grid[i][j] == '/')
                        visited[bI + k][bJ + 2 - k] = true;
                    else if(grid[i][j] == '\\')
                        visited[bI + k][bJ + k] = true;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < visited.size(); i++) {
            for(int j = 0; j < visited.size(); j++) {
                if(!visited[i][j]) {
                    ans++;
                    dfs(i, j, visited);
                }
            }
        }
        return ans;
    }
};