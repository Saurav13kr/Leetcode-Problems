class Solution {
public:
    int longestIdealString(string s, int k) {
        vector <int> dp(26, 0); 
        int ans = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int maxi = 0; 
            for (char ch = 'a'; ch <= 'z'; ch++) { 
                if (abs(s[i] - ch) <= k) {
                    maxi = max(maxi, dp[ch - 'a'] + 1); 
                }
            }
            
            ans = max(ans, maxi); 
            dp[s[i] - 'a'] = maxi; 
        }
        return ans;
    }
};