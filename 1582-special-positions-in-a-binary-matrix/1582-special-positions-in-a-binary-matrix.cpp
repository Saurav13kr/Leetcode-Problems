class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowOne(m), colOne(n);
        for(int i = 0; i < m; i++) {
            rowOne[i] = accumulate(mat[i].begin(), mat[i].end(), 0);
            for(int j = 0; j < n; j++) {
                colOne[j] += mat[i][j];
            }
        }
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans += mat[i][j] == 1 && rowOne[i] == 1 && colOne[j] == 1;
            }
        }
        return ans;
    }
};
