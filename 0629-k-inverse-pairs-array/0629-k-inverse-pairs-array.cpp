class Solution {
public:
    int kInversePairs(int n, int k) {
        if (n<2) return k==0;
        vector<vector<long long>> dp(n+1, vector<long long>(k+1));
        int M = 1000000007;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for (int j=0;j<=k;j++){
                if (j==0) dp[i][j]=1;
                else {
                    dp[i][j]=(dp[i-1][j] + M + dp[i][j-1] - (j>=i?dp[i-1][j-i]:0))%M;
                }
            }
        }
        return dp[n][k];
    }
};