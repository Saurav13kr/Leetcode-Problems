class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        vector<bool>visited(n,false);

         while(!q.empty()){
             int top = q.front();
             visited[top]=true;
              q.pop();
             for(auto v:rooms[top]){
               if(!visited[v]){
                  q.push(v);
               }
             }
         };

         for(auto c:visited){
             if(c==false){
                 return false;
             }
         }
         return true;
    }
};