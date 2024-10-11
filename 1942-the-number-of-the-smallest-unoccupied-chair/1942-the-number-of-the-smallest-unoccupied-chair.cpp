class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
           int n = times.size();
           for(int i=0;i<n;i++) times[i].push_back(i);
           
           sort(times.begin(), times.end());

            priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; 
            priority_queue <int, vector<int>, greater<int>> occupied;
            int j = 0;
        
           for(int i=0;i<n;i++) 
           {
            if(!pq.empty() && pq.top().first <= times[i][0]) {
                while(!pq.empty() && pq.top().first <= times[i][0]) {
                    occupied.push(pq.top().second);
                    pq.pop();
                }
            }

            int idx;
            if(occupied.empty()) 
            {
                idx = j;
                pq.push({times[i][1], j++});
            }
            else {
                idx = occupied.top();
                pq.push({times[i][1], idx});
                occupied.pop();
            }

            if(times[i][2] == targetFriend) {
               return idx;
            }
           }

           return -1;
    }
};
