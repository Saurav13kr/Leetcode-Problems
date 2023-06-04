class Solution {
    public:
    int orangesRotting(vector<vector<int>>&grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 2) {
                    q.push({0,{i,j}});
                }
            }
        }
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int ro = q.front().second.first;
            int cl = q.front().second.second;
            ans = q.front().first;
            visited[ro][cl] = 1;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int ne_row = ro + del_row[i];
                int ne_col = cl + del_col[i];
                if (ne_row < n && ne_row >= 0 && ne_col < m && ne_col >= 0 && !visited[ne_row][ne_col] &&
                    grid[ne_row][ne_col] == 1) {
                    grid[ne_row][ne_col] = 2;
                    q.push({ans+1,{ne_row,ne_col}});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};