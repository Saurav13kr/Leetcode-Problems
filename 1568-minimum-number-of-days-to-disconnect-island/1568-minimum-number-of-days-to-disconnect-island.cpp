#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
            return;
        
        visited[i][j] = 1;
        
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
    }
    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int islandCount = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    islandCount++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        
        return islandCount;
    }
    
    int minDays(vector<vector<int>>& grid) 
    {
        int islands = countIslands(grid);        
        if (islands != 1)
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // Temporarily change to water
                    
                    if (countIslands(grid) != 1)
                        return 1; // If it disconnects the grid, return 1
                    
                    grid[i][j] = 1; // Revert back to land
                }
            }
        }      
        return 2;
    }
};
