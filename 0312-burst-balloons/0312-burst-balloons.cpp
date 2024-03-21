class Solution {
public:
    int f(int i, int j, vector<int>&nums, vector<vector<int>>&dp)
    {
        int n = nums.size();
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans= 0;
        for(int k = i; k<=j; k++)
        {
            int temp= nums[k];
            if(j+1<n) temp*=nums[j+1];
            if(i-1>=0) temp*=nums[i-1];
            
            temp+=(f(i, k-1,nums, dp) + f(k+1, j, nums, dp));
            ans = max(ans, temp);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        f(1, n-2, nums, dp);
        return dp[1][n-2];
    }
};