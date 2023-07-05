class Solution {
    private:
        bool dfs(int node, vector<vector < int>> &graph, vector< int > &vis, vector< int > &pathVisited, vector< int > &safeNodes)
        {
            vis[node] = 1;	
            pathVisited[node] = 1;	

            for (auto it: graph[node])
            {
                if (!vis[it])
                {
                    if (dfs(it, graph, vis, pathVisited, safeNodes) == true) return true;
                }
                if (pathVisited[it] == 1 && vis[it] == 1) return true;	
            }
            safeNodes[node] = 1;	
            pathVisited[node] = 0;	
            return false;	
        }
    public:
        vector<int> eventualSafeNodes(vector<vector < int>> &graph)
        {
            int V = graph.size();
            vector<int> vis(V, 0);
            vector<int> pathVisited(V, 0);
            vector<int> safeNode(V, 0);
     
            for (int i = 0; i < V; i++)
            {
                if (!vis[i])
                {
                    dfs(i, graph, vis, pathVisited, safeNode);	
                }
            }

            vector<int> ans;	
            
            for (int i = 0; i < V; i++){
                if (safeNode[i] == 1) ans.push_back(i);
            }
            return ans;
        }
};