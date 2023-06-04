class Solution {
public:
    long long totalCost(vector<int>& costs, int m, int candidates) {
        long long ans = 0, i, j, end, start, n;
        n=costs.size();
        priority_queue<int,vector<int>,greater<int>> a,b;

        for(i=0; i<candidates; i++) {
            a.push(costs[i]);
        }
        for(i = n-1; i>=candidates && i >= n-candidates; i--) {
            b.push(costs[i]);
        }
        start = candidates;
        end = n- candidates-1;
        
        while(m > 0){
            if(a.empty() == false && b.empty() == false) {
                if(a.top() <= b.top()) {
                    ans = ans + a.top();
                    a.pop();
                    
                    if(start <= end){
                        a.push(costs[start]);
                        start++;
                    }
                } else {
                    ans = ans + b.top();
                b.pop();
                if(start <= end){
                    b.push(costs[end]);
                    end--;
                }
              }
            }
            else if(a.empty() == false) {
                ans = ans + a.top();
                a.pop();
            }
            else if(b.empty() == false) {
                ans = ans + b.top();
                b.pop();
            }
               m--; 
            }
        return ans;
        }
};