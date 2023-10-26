class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,bool>mp;
        unordered_map<int,int>dp;
        sort(arr.begin(),arr.end());
        int mod = 1e9 + 7;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            mp[arr[i]] = true;
            dp[arr[i]] = 1;
        }
        
        for(int i = 1;i < n;i++){
            int count = 0;
            for(int j = 0;j < n;j++){
                if(arr[j] > sqrt(arr[i]))
                    break;
                if(arr[i]%arr[j] == 0){
                    int p = arr[i]/arr[j];
                    if(mp[p] == true){
                        long long temp = (long long)dp[arr[j]]*dp[p];
                        if(arr[i]/arr[j] == arr[j])
                            dp[arr[i]] = (dp[arr[i]] + (temp)%mod)%mod;
                        else
                            dp[arr[i]] = (dp[arr[i]] + (temp*2)%mod)%mod;
                    }
                }
            }
        }
        int ans = 0;
        
        for(auto i:dp)
            ans = (ans + i.second)%mod;
        return ans;
    }
};