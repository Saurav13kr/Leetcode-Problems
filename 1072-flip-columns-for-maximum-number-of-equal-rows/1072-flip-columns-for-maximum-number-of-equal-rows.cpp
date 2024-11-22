class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>,int>maps;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            bool test=true;
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=matrix[i][0]){
                    test=false;break;
                }
            }
            if(test==true){
                maps[{0,0,0}]++;
            } else{
                vector<int>zero,one;
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==0){
                        one.push_back(j);
                    }else{
                        zero.push_back(j);
                    }
                }
                maps[zero]++;
                maps[one]++;
            }
        }
        int res=0;

        for(auto &k:maps){
            if(k.second>res){
                res=k.second;
            }
        }
        

        return res;
    }
};