class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<pair<int,int>>row;
        vector<pair<int,int>>col;

        int onecount=0;
        int zcount=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    onecount++;
                }else{
                    zcount++;
                }
            }
            row.push_back({onecount,zcount});
            onecount=zcount=0;
        }
        onecount=zcount=0;

        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                    onecount++;
                }else{
                    zcount++;
                }
            }
            col.push_back({onecount,zcount});
            onecount=zcount=0;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                grid[i][j]=row[i].first+col[j].first-row[i].second-col[j].second;
            }
        }

        return grid;

    }
};