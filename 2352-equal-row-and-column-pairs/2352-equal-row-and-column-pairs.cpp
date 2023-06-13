class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> counter;
        int row = grid.size(), col = grid[0].size(), c = 0;
        
        for (vector<int> row : grid) {
            counter[row] += 1;
        }
        
        for (int i = 0; i < row; i++) {
            vector<int> column_list = {};
            for (int j = 0; j < col; j++) {
                column_list.push_back(grid[j][i]);
            }
            c += counter[column_list];
        }
        
        return c;
    }
};