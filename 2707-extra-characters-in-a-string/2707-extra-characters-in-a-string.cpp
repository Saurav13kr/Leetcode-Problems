class Solution {
public:
    unordered_set<string> st;
    int dp[51];
    int solve(string& s, int index) {
        if (index >= s.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }
        int len = INT_MAX;
        
        for (int i = 1; i <= s.size(); i++) 
        {
            string str = s.substr(index, i);
            if (st.find(str) != st.end()) {
                len = min(len, solve(s, index + i));
            }
        }

        len = min(len, 1 + solve(s, index + 1));
        return dp[index] = len;
    }
    int minExtraChar(string s, vector<string>& d) {
        for (int i = 0; i < d.size(); i++) {
            st.insert(d[i]);
        }
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};