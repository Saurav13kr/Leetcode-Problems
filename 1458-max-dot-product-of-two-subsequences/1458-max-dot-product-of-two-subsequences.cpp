class Solution {
public:
    int dp[501][501];
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i<501; i++) { // memset fails here 
            for(int j = 0; j < 501; j++) {
                dp[i][j] = -1e9;
            }
        }
        return solve(nums1,nums2,0,0);
    }
    int solve(vector<int>&nums1,vector<int>&nums2,int i, int j){
        if(i==nums1.size()|| j==nums2.size())
            return -1e9;
        if(dp[i][j]!= -1e9)
            return dp[i][j];
        int val=nums1[i]*nums2[j];
        int r3=val + solve(nums1,nums2,i+1,j+1);
        int r1=solve(nums1,nums2,i+1,j);
        int r2=solve(nums1,nums2,i,j+1);
        
        
        return dp[i][j]=max({r1,r2,r3,val});
        
    }
};