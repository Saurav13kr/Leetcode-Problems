class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v(n + 1, 0); 
        vector<int>v2(n + 1, 0);       
        for(int i = 0; i < trust.size(); ++i){
            v[trust[i][1]]++;
            v2[trust[i][0]]++;
        }
        for(int i = 1; i <= n; ++i){
            if(v[i] == n - 1 && v2[i] == 0){
               return i;
            }
        }
        return -1;
    }
};