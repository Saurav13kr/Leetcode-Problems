class Solution {
public:
  int mod=1e9+7;
  int dp[20001][5];
    
    int helper(int n,int index,vector<int>arr[]){
        if(n==0)return 1;
        if(dp[n][index]!=-1)return dp[n][index];
        long long ans=0;
        
        for(auto &it: arr[index]){
            ans= (ans+helper(n-1,it,arr))%mod;
        }
        return dp[n][index]=(int)ans;
    }
    
    int countVowelPermutation(int n) {        
        vector<int> arr[5];
        memset(dp,-1,sizeof(dp));
       
        arr[0]={1};
        arr[1]={0,2};
        arr[2]={0,1,3,4};
        arr[3]={2,4};
        arr[4]={0};
        
        int ans=0;
        for(int i=0;i<5;i++){
            ans= (ans+ helper(n-1,i,arr))%mod;
        }
        return ans;
    }
};