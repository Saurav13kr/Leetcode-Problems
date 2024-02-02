class Solution {
public:
    int power(int a, int b){
	if(b==0){
		return 1;
	}
	int res = power(a,b/2);
	if(b%2==0){
	   return res * res;
	}
	else{
	   return a * res * res;
	}
}
int f(vector<vector<int>>&tree,vector<int>&coins,int k,int n,int v,int p,int flag,vector<vector<int>>&dp)
{
    if(dp[v][flag]!=-1)
    return dp[v][flag];
    int ans=coins[v]/power(2,flag)-k;
    int ans2=coins[v]/power(2,flag+1);
    for(auto it:tree[v])
    {
        if(it!=p)
        {
            ans+=f(tree,coins,k,n,it,v,flag,dp);
            if(flag<15)
            ans2+=f(tree,coins,k,n,it,v,flag+1,dp);
        }
    }
    return dp[v][flag]=max(ans,ans2);
}
 int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n=edges.size()+1;
        vector<vector<int>>tree(n);
        vector<vector<int>>dp(n,vector<int>(16,-1));
        for(auto it:edges)
        {
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }
        return f(tree,coins,k,n,0,-1,0,dp);
    }
};