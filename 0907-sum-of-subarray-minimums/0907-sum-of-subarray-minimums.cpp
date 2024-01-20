class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int res = arr[0], n = arr.size(), M = 1e9 + 7;
        vector<int> dp(n);
        dp[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] >= arr[i - 1]) dp[i] = dp[i - 1] + arr[i];
            else {
                int j = i - 1;
                while (j >= 0 && arr[i] < arr[j]) --j;
                dp[i] = (j < 0) ? (i + 1) * arr[i] : (dp[j] + (i - j) * arr[i]);
            }
            res = (res + dp[i]) % M;
        }
        return res;
    }
};