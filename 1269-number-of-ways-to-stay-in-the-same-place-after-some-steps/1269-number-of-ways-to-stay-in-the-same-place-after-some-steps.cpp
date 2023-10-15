class Solution {
private:
    int64_t mod = 1000000007;
    int64_t numWays(int steps, int index, vector<vector<int>>& dp) {
        if (index < 0 || index >= dp[steps - 1].size() || (index - steps) > 0) {
            return 0;
        }

        if (steps == 1) {
            return index <= 1;
        }

        steps--;
        if (dp[steps][index] != -1) {
            return dp[steps][index];
        }

        dp[steps][index] =  ((numWays(steps, index - 1, dp)  +
                            numWays(steps, index, dp)) % mod +
                            numWays(steps, index + 1, dp)) % mod;
        return dp[steps][index];
    }

public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps, vector<int>(std::min(steps + 1, arrLen), -1));
        return numWays(steps, 0, dp);
    }
};