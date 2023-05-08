class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
		int diag1=0,diag2=0;
        for(int i=0;i<mat.size();i++){
		
            diag1+=mat[i][i];
            diag2+=mat[i][mat[0].size()-1-i];
        }
		
        if(mat.size()%2!=0){
            diag1-=mat[mat.size()/2][mat.size()/2];
        }
        return diag1+diag2;
    }
};