class Graph {
public:
    vector<vector<pair<int,int>>> v;
    Graph(int n, vector<vector<int>>& edges) {
        v.resize(n);
        for(auto it:edges){
            v[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        v[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dis(v.size(),INT_MAX);
        dis[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            auto dist=pq.top().first;
            auto node=pq.top().second;
            pq.pop();
            if(dist>dis[node])continue;
            if(node==node2)return dist;
            for(auto it:v[node]){
                if(dis[it.first]>dist+it.second){
                    dis[it.first]=dist+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        return (dis[node2]==INT_MAX)? -1:dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */