#define ll long long
class Solution{
public:
    int m = 1e9 + 7;
    int countOrders(int n){
        ll dp[n + 1];
        dp[1] = 1;
        for (ll i = 2; i <= n; i++){
            dp[i] = ((dp[i - 1] % m * (i) % m) % m * (2 * i - 1) % m) % m;
        }

        return dp[n];
    }
};