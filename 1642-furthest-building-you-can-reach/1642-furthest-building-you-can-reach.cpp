class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        for(int i=1;i<n;i++){
            int h = heights[i]-heights[i-1];
            if(heights[i] > heights[i-1]){
                if(bricks >= h){
                    bricks -= h;
                    pq.push(h);
                }else{
                    if(!pq.empty() && pq.top()>h){
                        if(ladders>0) ladders--;
                        else return i-1;
                        bricks += pq.top();
                        pq.pop();
                        bricks -= h;
                        pq.push(h);
                    }else{
                        if(ladders>0) ladders--;
                        else return i-1;
                    }
                }
            }
        }
        return n-1;
    }
};