class Solution {
public:
    int rob(vector<int>& nos) {
        if(nos.size() == 1)return nos[0];
        vector<int>dp(nos.size());
        
        dp[0] = nos[0];
        dp[1] = max(nos[0], nos[1]);
        
        for(int i = 2; i < nos.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nos[i]);
        }
        
        return dp[nos.size() - 1];
    }
};