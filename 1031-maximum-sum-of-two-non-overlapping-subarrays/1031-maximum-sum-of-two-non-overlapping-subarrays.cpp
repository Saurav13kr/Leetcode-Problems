class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int size = nums.size();
        int dp[size][4];    // state 0~3: {isSkipSecondArr, isSkipFirstArr};
        memset(dp, 0, sizeof(dp));
        dp[0][0] = nums[0];
        for (int i = 1; i < size; i++) {
            dp[i][0] = dp[i - 1][0] + nums[i];
        }
        for (int i = firstLen; i < size; i++) 
        {
            dp[i][1] = min(dp[i - firstLen][0], dp[i - 1][1] + nums[i]);
        }
        // dp[secondLen - 1][2] = 0;
        for (int i = secondLen; i < size; i++) {
            dp[i][2] = min(dp[i - secondLen][0], dp[i - 1][2] + nums[i]);
        }
        // dp[firstLen + secondLen - 1][3] = 0;
        for (int i = firstLen + secondLen; i < size; i++) {
            dp[i][3] = min(dp[i - 1][3] + nums[i],
                            min(dp[i - firstLen][2], dp[i - secondLen][1]));
        }
        return dp[size - 1][0] - dp[size - 1][3];
    }
};