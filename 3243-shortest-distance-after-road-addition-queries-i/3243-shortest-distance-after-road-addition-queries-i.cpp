class Solution {
public:
    int shortestPath(int n,vector<vector<int>>gr){
        int ans=0;
        queue<int>q;
        q.push(0);
        vector<int>vis(n);
        vis[0]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--)
            {
                int cur=q.front();
                q.pop();
                if(cur==(n-1))
                {
                    return ans;
                }
                for(auto&i:gr[cur])
                {
                    if(!vis[i]){
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<int>>gr(n);
        for(int i=0;i<n-1;i++)
        {
            gr[i].push_back(i+1);
        }
        for(auto&q:queries)
        {
            gr[q[0]].push_back(q[1]);
            res.push_back(shortestPath(n,gr));
        }
        return res;
    }
};