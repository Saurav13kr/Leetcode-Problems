class Solution {
private:
    int solve (int len, int low, int high, int zero, int one, vector<int> &dp) {
        if (len > high) {
            return 0;
        } 
        if (dp[len] != -1) {
            return dp[len];
        }        
        int left = solve (len + zero, low, high, zero, one, dp);
        int right = solve (len + one, low, high, zero, one, dp);     
        return dp[len] = (left + right + (len >= low)) % int(1e9 + 7);
    }    
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(0, low, high, zero, one, dp);
    }
};