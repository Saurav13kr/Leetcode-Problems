class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0)
            return {};
        if(n == 1)
            return {0};
        if(n == 2)
            return {0, 1};
        vector<int> ans;
        vector<int> adj[n];
        vector<int> degree(n, 0);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            degree[u]++;
            degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(degree[i] == 1) q.push(i);

        while(!q.empty()){
            int count = q.size();
            ans.clear();
            while(count--){
                int node = q.front();
                q.pop();
                ans.push_back(node);
               
                for(auto adjNode : adj[node]){
                    degree[adjNode]--;
                    if(degree[adjNode] == 1)
                        q.push(adjNode);
                }
            }
        }
        return ans;
    }
};