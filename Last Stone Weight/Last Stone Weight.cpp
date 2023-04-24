class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int>pq(begin(v),end(v));

        while(!pq.empty()){
            if(pq.size() == 1)
            {
                return pq.top();
                pq.pop();
            }
                
            else if(pq.size()>2)
            {
                int x=pq.top();
                pq.pop();
                int y=pq.top();
                pq.pop();
                if(x!=y){
                pq.push(abs(x-y));
                }
            }

            else if(pq.size()==2)
            {
                int x=pq.top();
                pq.pop();
                int y=pq.top();
                pq.pop();
                return abs(x-y);
            }
        }

        return 0;
        
    }
};
