class Solution {
public:
    vector<pair<int,int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
    bool isPossible(vector<vector<int>>& heights,int i,int j,vector<vector<int>>&vis,int k,vector<vector<int>>& dp){
        if(i==heights.size()-1 && j==heights[0].size()-1){
            return true;
        }
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        vis[i][j] = 1;
        int ans = false;

        for(auto [dx,dy]:dirs){
            if(i+dx<0 || j+dy<0 || i+dx>=heights.size() || j+dy>=heights[0].size() || vis[i+dx][j+dy]){
                continue;
            }
            int diff = abs(heights[i][j]-heights[i+dx][j+dy]);
            if(diff>k) 
                continue;
            ans = ans || isPossible(heights,i+dx,j+dy,vis,k,dp);
        }
        vis[i][j] = 0;
        return dp[i][j] = ans;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {        
        int m = heights.size(),n = heights[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){

                mini = min(mini,heights[i][j]);
                maxi = max(maxi,heights[i][j]);
            }
        }
        int l = 0,h = (maxi-mini);        
        while(l<h){
            int mid = (h+l)/2;
            vector<vector<int>> vis(m, vector<int>(n,0));
            vector<vector<int>> dp(m,vector<int> (n,-1));
            if(isPossible(heights,0,0,vis,mid,dp)){
                h = mid;
            }
            
            else{
                l = mid+1;
            }
            vis.clear();
        }
        return h;
    }
};