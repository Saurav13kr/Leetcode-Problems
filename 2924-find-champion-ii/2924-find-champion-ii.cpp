class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int>m;

        for(auto x : edges)
        {
            m.insert(x[1]);
        }

        if(m.size() < n-1)
        {
            return -1;
        }

        for(int i=0 ; i<n ; i++)
        {
            if(m.find(i) == m.end()){
                return i ;
            }
        }

        return -1 ;
    }
};