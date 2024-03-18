class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        sort(v.begin() , v.end());
        int cnt = 0;
        int n = v.size();
        for(int i = 1 ; i < n ; i++){
            if(v[i][0] <= v[i-1][1]){
                cnt++;
                v[i][1] = min(v[i][1], v[i-1][1]);
            }
        }
        return n - cnt;
    }
};