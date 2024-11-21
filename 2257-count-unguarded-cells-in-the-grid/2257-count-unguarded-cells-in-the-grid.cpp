class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<pair<int,int>>> res(m, vector<pair<int,int>> (n, {0,0}));
        for(auto g:guards) res[g[0]][g[1]] = pair<int,int> {1,1};
        for(auto w:walls) res[w[0]][w[1]] = pair<int,int> {-1,-1};

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (res[i][j].first != -1){
                    if(j>0 && res[i][j-1].first == 1) res[i][j].first = 1;
                    if(i>0 && res[i-1][j].second == 1) res[i][j].second = 1;
                }
            }
        }
     
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if (res[i][j].first != -1){
                    if(j<n-1 && res[i][j+1].first == 1) res[i][j].first = 1;
                    if(i<m-1 && res[i+1][j].second == 1) res[i][j].second = 1;
                }
            }
        }
        int count=0;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if (res[i][j].first==0 && res[i][j].second==0) count++;
            }
        }
        return count;
    }
};