class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b) {
        if(a.first!=b.first) return a.first<b.first;      
        return a.second<b.second; 
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& g, int k) {
        vector<pair<int,int>> v;
        vector<int> a;
        
        for(int i=0;i<g.size();i++){
         int s=0;
         for(int j=0;j<g[0].size();j++)
            if(g[i][j]==1) s++;           
           v.push_back({s,i});
        }
        
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<k;i++)
        a.push_back(v[i].second);

        return a;
    }
};