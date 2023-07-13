class Solution {
public:
    bool isMatch(string s2, string s1) {

        int n = s1.size(), m = s2.size();
    
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        dp[0][0] = 1;
        for(int i = 1; i<=n; i++){
                bool b = true;
                for(int k = 0; k<i; k++){
                    if(s1[k] != '*'){
                        b = false;
                        break;
                    }
                }
                if(b) dp[i][0] = 1;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){         
                if(s1[i-1] == s2[j-1] || s1[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(s1[i-1] == '*') dp[i][j] = dp[i][j-1] || dp[i-1][j];     
            }
        }

        return dp[n][m];
    }
};