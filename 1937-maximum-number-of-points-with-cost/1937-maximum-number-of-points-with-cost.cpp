using ll = long long;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<ll> dp(points[0].begin(),points[0].end());
        for (int i = 1; i < n; i++){
            ll mx = 0;
            vector<ll> temp(m);
            for (int j = 0; j < m; j++)
            {
                mx = max(mx,dp[j]);
                temp[j] = max(mx+points[i][j], temp[j]);
                mx--;
            }
            mx = 0;
            for (int j = m-1; j >= 0; j--){
                mx = max(mx,dp[j]);
                temp[j] = max(mx+points[i][j], temp[j]);
                mx--;
            }
            dp = temp;
        }
        return *max_element(dp.begin(),dp.end());
    }
};