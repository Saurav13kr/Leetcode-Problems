class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int count=0;
        vector<int>ds;
        vector<int>dp(target+1,-1);
       
        return  solve(dp,target,count,0,0,nums);;
    }
     int solve(vector<int>&dp,int  target,int cnt,int idx,int sum,vector<int>&nums){
       if(target<0) return 0;
       if(target==0) return 1;
        int take = 0;
        if(dp[target] != -1) return  dp[target];
        for(int k=0 ; k<nums.size() ; k++){
            take+=solve(dp,target-nums[k],cnt,idx,sum,nums);
        }
        return dp[target]=take;
      
    }
};