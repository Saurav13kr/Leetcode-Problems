class Solution {
    int mod;
public:
    int dfs(int src,int n,unordered_map<int,vector<int>> &mp,vector<vector<int>> &dp){
        if(n==0)
            return 1;
        if(dp[src][n]!=0)
            return dp[src][n];
        for(int child : mp[src]){
            dp[src][n] = (dp[src][n]+dfs(child,n-1,mp,dp))%mod;
        }
        return dp[src][n]%mod;
    }
    int knightDialer(int n) {
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> dp(10,vector<int> (n,0));
        mod = 1000000007;
        mp[0] = {4,6};
        mp[1] = {8,6};
        mp[2] = {7,9};
        mp[3] = {4,8};
        mp[4] = {0,3,9};
        mp[6] = {1,7,0};
        mp[7] = {2,6};
        mp[8] = {1,3};
        mp[9] = {4,2};
        
        int count=0;
        for(int i=0;i<=9;i++){
            count=(count+dfs(i,n-1,mp,dp))%mod;
        }
        return count;
    }
};