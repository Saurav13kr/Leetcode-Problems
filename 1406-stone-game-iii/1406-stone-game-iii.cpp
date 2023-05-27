class Solution {
public:
    int dp[50005];
    
    int solve(int i, vector<int>&a){
        int n=a.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int alice=0,ans=INT_MIN;
        
        for(int k=i;k<min(n,i+3); k++){
            alice+=a[k];
            ans=max(ans, alice+min({solve(k+2,a), solve(k+3,a) , solve(k+4,a)}));
        }
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof dp);
        int aliceScore=solve(0,stoneValue);
        
        int bobScore=accumulate(stoneValue.begin(),stoneValue.end(),0)-aliceScore;
        if(aliceScore>bobScore) return "Alice";
        else if(aliceScore==bobScore) return "Tie";
        return "Bob";
    }
};