class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int s = grid.size();
        int c = 0;

        for(int i=0; i<s; i++) {
            int ub = upper_bound(grid[i].rbegin(),grid[i].rend(),-1) - grid[i].rbegin();
            c += ub;
        }    
        return c;
    }
};