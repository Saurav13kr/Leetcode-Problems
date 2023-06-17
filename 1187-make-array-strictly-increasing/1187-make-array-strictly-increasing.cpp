class Solution {
public:
    int d[2001][2001] = {} , h = 2001;
    int solve(vector<int>& a, vector<int>& b,int i, int j, int g) {
        
        if(i >= a.size())
            return 0;
        j = upper_bound(b.begin() , b.end() , g) - b.begin();
        if( g >= a[i] && j >= b.size() )
            return h;        
        if(d[i][j] == 0)
        d[i][j] = j < b.size() ? 1 + solve(a,b,i+1,j,b[j]):h;
        
        if(g < a[i])
            d[i][j] = min(d[i][j] , solve(a,b,i+1,j,a[i]));
        return d[i][j];
    }
    
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        sort(b.begin() , b.end());
        int p = solve(a,b,0,0, -1e9);
        
        return p>=h ? -1:p;
    }
};