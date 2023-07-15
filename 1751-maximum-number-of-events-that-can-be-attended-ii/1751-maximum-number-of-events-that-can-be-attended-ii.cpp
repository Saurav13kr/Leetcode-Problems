class Solution {
public:
    int solve(vector<vector<int>>& events, int k, int n, int idx, vector<vector<int>> &dp) {
        if(k == 0 || idx == n) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];

        int i = 0;
        for(i = idx + 1; i < n; i++) {
            if(events[i][0] > events[idx][1]) break;
        }
return dp[idx][k] = max(solve(events, k, n, idx + 1, dp), events[idx][2]+solve(events, k - 1, n, i, dp));
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        sort(events.begin(), events.end());
        return solve(events, k, n, 0, dp);
    }
};