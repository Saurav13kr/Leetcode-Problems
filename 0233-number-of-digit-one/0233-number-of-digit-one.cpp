class Solution {
public:
    long long dp[10][10];
    int a[11];

    int dfs(int pos, bool limit, int sum){
        if(pos == 0){
            return sum;
        }
        if(!limit && dp[pos][sum] != -1){
            return dp[pos][sum];
        }
        int bound = limit?a[pos]:9;
        int res = 0;
        for(int i = 0; i <= bound; i++){
            res = res + dfs(pos-1, limit&&(i==bound), sum+(i==1));
        }
        if(!limit) dp[pos][sum] = res;
        return res;

    }

    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        int len = 0;
        while(n){
            a[++len] = n%10;
            n /= 10;
        }
        return dfs(len, true, 0);
        
    }
};