#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
          priority_queue<int,vector<int>,greater<int>> freeRooms;
       
        for(int i=0;i<n;i++){
            freeRooms.push(i);
        }
        
         
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        
        vector<int> count(n,0);
        
        for(auto meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];
                        
            while(pq.size()>0 && start>=pq.top().first){
                freeRooms.push(pq.top().second);
                pq.pop();
            }
            
            if(freeRooms.size()>0){
                count[freeRooms.top()]++;
                pq.push({end,freeRooms.top()});
                freeRooms.pop();
            } else{
            
                ll endTime = pq.top().first;
                ll roomNo = pq.top().second;
                pq.pop();

                pq.push({endTime+end-start,roomNo});
                count[roomNo]++;
            }
        }
        
        int minRoom = 1e9;
        int maxCount = 0;
        for(int i=0;i<n;i++){
            if(count[i]>maxCount){
                maxCount = count[i];
                minRoom = i;
            }
        }
        return minRoom;
    }
};