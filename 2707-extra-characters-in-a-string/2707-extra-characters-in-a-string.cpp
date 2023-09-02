class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> DP(n + 1);
        DP[0] = 0;
        
        for(int i = 0; i < n; i++) {
            DP[i + 1] = 1 + DP[i];
            
            for(string c: dictionary) {
                int len = c.length();                
                if(i >= len - 1 && c == s.substr(i - len+1, len)) {
                    DP[i+1] = min(DP[i + 1], DP[i - len+1]);
                }
            }
        }
        return DP[n];
    }
};