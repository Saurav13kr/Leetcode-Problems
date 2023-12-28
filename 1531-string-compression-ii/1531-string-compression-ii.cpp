class Solution {
public:

    int MAX=10000;
    int dp[105][105];
    string s;
    int fun(int x){
        if(x==1){
            return 1;
        }
        return 1+to_string(x).size();
    }
    int solve(int idx,int n,int k){
        if(k<0){
            return MAX;
        }
        if(idx==n){
            return 0;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        int ans=MAX,count=0,count1=0,i;
        ans=min(ans,solve(idx+1,n,k-1));
        for(i=idx;i<n;i++){
            if(s[idx]==s[i]){
                count++;
            }
            else{
                count1++;
            }
            if(count1<=k){
                ans=min(ans,fun(count)+solve(i+1,n,k-count1));
            }
        }
        dp[idx][k]=ans;
        return ans;
    }

    int getLengthOfOptimalCompression(string s1, int k) {
        s=s1;
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,s.size(),k);
        return ans;
    }
};