class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        priority_queue<pair<int , int>, vector<pair<int , int>>, greater<pair<int, int>>>pq;
        vector<int>time1(n , 1e9), time2(n , 1e9);
        int freq =0;
        pq.push({0 , 0});
        
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if((dist/change)%2 ==1)dist+= change-dist%change;
            if(freq==2 && node ==n-1)break;
            if(node ==n-1)freq++;
            
            for(auto it : adj[node])
            {
             if(dist+time < time1[it]){
                time2[it] = time1[it];
                time1[it] = dist+time;
                pq.push({time1[it], it});
             }
             else if (dist+time < time2[it]&& dist+time != time1[it]){
                time2[it]= dist+time;
                pq.push({time2[it], it});
             }
            }
        }
        return time2[n-1];
    }
};