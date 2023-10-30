class Solution {
public:
bool fun(int idx,vector<int>& nums,int sum,float target,float t,int cnt,vector<vector<vector<bool>>>&dp)
{
    if(idx>=0)
    {
        if(t==0)
        return true; 
    }
    else
    return false;
    
    float temp=sum+nums[idx];
    if(dp[idx][cnt][sum]==false)
    return false;
    return dp[idx][cnt][sum]=fun(idx-1,nums,sum+nums[idx],target,target-(temp/(cnt+1)),cnt+1,dp)||fun(idx-1,nums,sum,target,target,cnt,dp);
     
}
    bool splitArraySameAverage(vector<int>& nums) {
        if(nums.size()<2)
        return false;
        
       float sum=0;
       int count=0;
       int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            count++;
        }
        int m=sum;
        vector<vector<vector<bool>>>dp(n+1, vector<vector<bool>>(n+1, vector<bool>(m+1, true)));
        return fun(n-1,nums,0,sum/count,sum/count,0,dp);
    }
};