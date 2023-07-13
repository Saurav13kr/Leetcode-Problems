class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;
        vector<int>adj[n];
        vector<int>indegree(n,0);
        
        for(auto it:pre) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q1;
        
        for(int i=0;i<n;i++) {
            if(indegree[i]==0)
            {
                q1.push(i);
            }
        }
        int cnt = 0;
        
        while(!q1.empty()) {
            int x = q1.front();
            q1.pop();
            cnt++;
            
            for(auto it:adj[x]) {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q1.push(it);
                }
            }
        }
        return (cnt==n);
    }
};