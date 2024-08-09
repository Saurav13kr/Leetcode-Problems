class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] != 5) return false;

        int bits = 0;
        array<int, 8> sum {};

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                bits ^= 1 << grid[i + dx][j + dy];
                sum[dx + 1] += grid[i + dx][j + dy];
                sum[dx + 4] += grid[i + dy][j + dx];
            }
        }

        sum[6] = grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1];
        sum[7] = grid[i - 1][j + 1] + grid[i][j] + grid[i + 1][j - 1];

        return bits == 1022 && ranges::all_of(sum, [&](int x) {
            return x == 15;
        });
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        for (int i = 1; i < n - 1; i++) 
        {
            for (int j = 1; j < m - 1; j++) 
            {
                res += isMagic(grid, i, j);
            }
        }

        return res;
    }
};