class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {  
        
        int n=triangle.size();
        vector<int> store=triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                store[j]=triangle[i][j]+min(store[j],store[j+1]);
            }
        }
        return store[0];
    }
};