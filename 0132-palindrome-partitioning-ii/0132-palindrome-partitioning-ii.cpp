class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])
            return false;
            i++;j--;
        }
        return true;
    } 
    
    int mcm(string &s,int i,int j,vector<vector<int>> &dp){
        if(dp[i][j] != -1)return dp[i][j];
        if(i>=j)
        return dp[i][j] = 0;

        if(isPalindrome(s,i,j))
        return dp[i][j] = 0;

        int res = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int left,right;
            if(!isPalindrome(s,i,k))
            continue;
            if(dp[i][k]!=-1)
            left = dp[i][k];
            else{
                left = mcm(s,i,k,dp);
                dp[i][k]=left;
            }
            if(dp[k+1][j]!=-1)
            right = dp[k+1][j];
            else{
                right = mcm(s,k+1,j,dp);
                dp[k+1][j]=right;
            }
           int temp = left+right+1;
            if(temp < res)res = temp;
        }
    return dp[i][j] = res;
    }

    int minCut(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        return mcm(s,0,s.length()-1,dp);
    }
};