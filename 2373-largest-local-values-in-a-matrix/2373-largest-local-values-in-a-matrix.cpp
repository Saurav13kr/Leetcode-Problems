class Solution {
public: 
    int findMax(vector<vector<int>>& grid, int startRow, int startCol)
    {
        int maxVal =0;
        for(int i=startRow; i< startRow+3; i++)
        {
            for(int j=startCol; j< startCol+3; j++)
            {
                if(maxVal < grid[i][j]){
                    maxVal = grid[i][j];
                }
            }
        }
        return maxVal;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2,vector<int>(n-2));
        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-2; j++){
                res[i][j] = findMax(grid, i, j);
            }
        }
        return res;
    }
};