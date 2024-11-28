class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int  n = grid.size();
        int m = grid[0].size();

        set<pair<int  , pair<int  ,int>>>st;
        st.insert({0, {0, 0}});
        vector<vector<int>>dist(n ,vector<int>(m , INT_MAX));

        int dx[] = {-1, 0, 1,0 };
        int dy[] = {0, 1,0,-1};
        dist[0][0] = 0;

        while(!st.empty()){
             auto it = *(st.begin());
             st.erase(st.begin());
             int row = it.second.first;
             int col = it.second.second ;
             int cost = it.first;

             if (cost > dist[row][col]) continue;
             for(int k =0; k< 4; k++){
                  int nrow = row + dx[k];
                  int ncol = col + dy[k];

                  if(nrow >=0 && nrow< n && ncol < m && ncol >=0 ){
                       if(grid[nrow][ncol] == 0 && dist[nrow][ncol] > cost ){
                            dist[nrow][ncol] = cost;
                           st.insert({cost, {nrow , ncol}});
                          

                       }
                       else if(grid[nrow][ncol] == 1 && dist[nrow][ncol] > cost +1){
                            dist[nrow][ncol] = cost +1 ;
                            st.insert({cost +1 ,{nrow , ncol}});
                       }

                  }

             }

        }

        return dist[n-1][m-1];
    }
};