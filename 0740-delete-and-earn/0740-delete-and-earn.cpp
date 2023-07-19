class Solution {
public:
    int helper(int pos, vector<int>& a, vector<int>& dp) {
        int n=a.size();
        if(pos==0) return a[0];
        if(pos < 0) return 0;
        if(dp[pos]!=-1) return dp[pos];
        
        int pick = a[pos] + helper(pos-2,a,dp);
        int notPick = helper(pos-1,a,dp);
        return dp[pos] = max(pick,notPick);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> sum(maxi+1);
        
        for(auto it:nums) sum[it]+=it;
        vector<int> dp(maxi+1,-1);
        return helper(maxi,sum,dp);
    }
};