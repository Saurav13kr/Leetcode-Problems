class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int s=cost.size();
        vector<int> dp(3); 
        
        for (int j=2; j<=s; j++) {
            int jumpOneStep = dp[(j-1)%3] + cost[j-1];  
            int jumpTwoStep = dp[(j-2)%3] + cost[j-2];  
            dp[j%3] = min(jumpOneStep, jumpTwoStep);
        }
        
        return dp[s%3];
    }
};