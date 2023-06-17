class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        std::vector<std::vector<bool>> d(m+1, std::vector<bool>(n+1, false));
        d[0][0] = true; 

        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*')
                d[0][j] = d[0][j-2];
        }

        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (s[i-1] == p[j-1] || p[j-1] == '.') 
                {
                    d[i][j] = d[i-1][j-1];
                } 
                
                else if (p[j-1] == '*')
                {
                    d[i][j] = d[i][j-2]; 
                    if (s[i-1] == p[j-2] || p[j-2] == '.')
                    {
                        d[i][j] = d[i][j] || d[i-1][j]; 
                    }
                }
            }
        }
        
        return d[m][n];
    }
};