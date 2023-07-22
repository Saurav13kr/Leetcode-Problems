class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        int moves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{1,2},{2,1},{-1,2},{-2,1}};
        vector<vector<double>> v1(n,vector<double>(n,0));
        vector<vector<double>> v2(n,vector<double>(n,0));
        vector<vector<double>> &v = v1;
        vector<vector<double>> &vn = v2;
        v[row][column]=1;
        
        for(; k>0; k--) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    double f=v[i][j]/8; 
                    v[i][j] = 0;        
                    
                    for(int l=0; l<8; l++) {
                        int y=i+moves[l][0];
                        int x=j+moves[l][1];
                        if (y >=0 && y <n && x>=0 && x<n)
                            vn[y][x] += f;  
                    }
                }

            }
            swap(v,vn);
        }
        double ans = 0;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
               ans += v[i][j];  
        
        return ans;

    }
};