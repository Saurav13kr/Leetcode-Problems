class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp(pairs.size(), 1);
        sort(pairs.begin(), pairs.end());
        for (int j = 0; j < pairs.size(); j++) {
            for (int i = 0; i < j; i++) {
                if (pairs[i][1] < pairs[j][0]) {
                    dp[j] = 1 + dp[i];
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};