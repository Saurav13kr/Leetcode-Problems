class Solution {
public:
    vector<int>first = {100,75,50,25};
    vector<int>second = {0,25,50,75};
    double solve(int a,int b,vector<vector<double>>&dp){
        if(a<=0 && b<=0){
            return 0.5;
        }

        if(a<=0){
            return 1;
        }

        if(b<=0){
            return 0;
        }

        if(dp[a][b]!=-1){
            return dp[a][b];
        }

        double prob = 0;

        for(int i=0; i<4; i++){
            prob+=(0.25 * solve(a-first[i],b-second[i],dp));
        }
        dp[a][b]=prob;
        return prob;

    }
    double soupServings(int n) {

        if(n>=5000){
            return 1;
        }
      vector<vector<double>>dp(n+1,vector<double>(n+1,-1));  
    double ans = solve( n, n,dp);

    return ans;

    }
};