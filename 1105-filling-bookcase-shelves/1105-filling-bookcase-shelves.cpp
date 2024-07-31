class Solution {
public:
    int fn(int i,int wt,int ht,vector<vector<int>>& b,int w,vector<vector<int>>&dp){
        if(i==b.size())return ht;
        if(dp[i][wt]!=-1)return dp[i][wt];
        int next=INT_MAX;
        int same=INT_MAX;
        if(wt!=0) next=ht+fn(i+1,b[i][0],b[i][1],b,w,dp);
        if(wt+b[i][0]<=w){
            same=fn(i+1,wt+b[i][0],max(ht,b[i][1]),b,w,dp);
        }
        return dp[i][wt]=min(same,next);
    }
    int minHeightShelves(vector<vector<int>>& b, int w) 
    {
        int n=b.size();
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        return fn(0,0,0,b,w,dp);
    }
};