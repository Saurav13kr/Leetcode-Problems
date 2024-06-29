class Solution {
private:
    vector<vector<int>> adj, ans;
    void DFS(int curr, int par) {
        for (int child : adj[curr])
        {
            if (!ans[child].empty() && ans[child].back() == par)
                continue;
            ans[child].push_back(par);
            DFS(child, par);
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges){
        adj.resize(n);
        ans.resize(n);
        for (vector<int> edge : edges)
            adj[edge[0]].push_back(edge[1]);
        for (int i = 0; i < n; i++)
            DFS(i, i);
        return ans;
    }
};