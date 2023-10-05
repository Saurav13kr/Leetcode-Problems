class Solution {
public:
    bool divisorGame(int n) {
        vector<vector<bool>>dp(2,vector<bool>(n+1,false));
        if(n<2)
            return false;
        if(n==2)
            return true;
        dp[0][2]=true;
        dp[1][2]=false;
        
        for(int j=3;j<n+1;j++){
            bool a=true,b=true;
            for(int k=1;k<j;k++){
                if(j%k==0&&dp[1][j-k]){
                    dp[0][j]=true;
                    a=false;
                    break;
                }
            }
            if(a){
                dp[0][j]=false;
            }
            
            for(int k=1;k<j;k++){
                if(j%k==0 && dp[0][j-k]==false){
                    dp[1][j]=false;
                    b=false;
                    break;
                }
            }
            if(b)
                dp[1][j]=true;
        }
        return dp[0][n];
    }
};