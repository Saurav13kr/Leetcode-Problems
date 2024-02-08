class Solution {
public:
    int numSquares(int n) {
        vector<long> dp(n+1,INT_MAX);
        dp[0] = 0;
        for (long i=1;i<=n;i++) {
            for (long j=1;j * j <= i;j++) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
};