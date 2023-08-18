class Solution {
public:
    int total=0,maxrank=0;
    unordered_map<int,unordered_set<int>> adj;
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        for(auto &road :roads){
            int u=road[0];
            int v=road[1];

            adj[u].insert(v);
            adj[v].insert(u);
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) {
                int i_rank=adj[i].size();
                int j_rank=adj[j].size();
                total= i_rank +j_rank;
                if(adj[i].find(j) != adj[i].end()){
                    total-=1;
                }
                maxrank=max(maxrank,total);
            }
        }
        return maxrank;
    }
};