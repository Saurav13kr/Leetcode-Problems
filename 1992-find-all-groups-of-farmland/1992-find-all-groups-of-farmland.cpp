class Solution {
public:
    void dfs(int i,int j,int &a,int &b,int &c,int &d,vector<vector<int>>& land){
        int m=land.size();
        int n=land[0].size();
        land[i][j]=0;
        
        if(i<a || j<b)
        {
            a=i;b=j;
        }
        
        if(i>c || j>d){
            c=i;d=j;
        }
        
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        
        for(int k=0;k<4;k++){
            int e=i+drow[k];
            int f=j+dcol[k];
            if(e<m && e>=0 && f<n && f>=0  && land[e][f]){
                dfs(e,f,a,b,c,d,land);
            }
        }
    }
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size();
        int n=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1){
                    int a=i,b=j,c=i,d=j;
                    dfs(i,j,a,b,c,d,land);
                    vector<int>temp={a,b,c,d};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};