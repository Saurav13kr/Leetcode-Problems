class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long> dp(n + 1, 0);
        for (int index = n - 1; index >= 0; index--) {
            int maxm = INT_MIN;
            int range = min(index + k, n);
            for (int i = index; i < range; i++) {
                maxm = max(maxm, arr[i]);
                long long value = maxm * (i - index + 1) + dp[i + 1];
                dp[index] = max(value, dp[index]);
            }
        }

        return dp[0];
    }
};