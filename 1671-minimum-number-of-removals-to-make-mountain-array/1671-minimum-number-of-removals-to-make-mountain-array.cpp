class Solution {
public:
  
    int minimumMountainRemovals(vector<int>& nums) {
         int n = nums.size();
          vector<int>dp(n,0),dp2(n,0);
          
    
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
        }
       
        
       
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i] > nums[j])
                {
                    dp2[i] = max(dp2[i] , dp2[j] + 1);
                }
            }
        }
       
        
        int ans = n;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]>=1 and dp2[i]>=1 and dp[i]+dp2[i]>=2)
            ans = min(ans,n-dp[i]-dp2[i]-1);
           
        }
        
        
        return ans;
        
    }
};