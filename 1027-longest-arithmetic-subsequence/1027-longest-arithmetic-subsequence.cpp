class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int c = 0;
        vector<unordered_map<int, int>> dp(n);
        
        for (int i=0; i<n; i++) {
            
            for (int j = 0; j < i; j++) {
                int diff = A[i]-A[j];
                dp[i][diff] = dp[j].count(diff)>0 ? dp[j][diff] + 1 : 2;
                c = max(c, dp[i][diff]);
            }
        }
        return c;
    }
};