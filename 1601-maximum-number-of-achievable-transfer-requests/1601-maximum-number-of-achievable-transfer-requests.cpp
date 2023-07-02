class Solution {
    int ans = INT_MIN;
public:
    void solve(int n, vector<vector<int>>& req, vector<int> &blocks, int ind, int count){
        if(ind==req.size()){
            for(int i=0; i<n; i++){
                if(blocks[i] != 0){  
                    return;
                }
            }
            
            ans = max(ans, count);
            return;
        }
        
        blocks[req[ind][0]]--;
        blocks[req[ind][1]]++;
        solve(n, req, blocks, ind+1, count+1);
        blocks[req[ind][0]]++;
        blocks[req[ind][1]]--;    

        solve(n, req, blocks, ind+1, count); 
    }
    
    int maximumRequests(int n, vector<vector<int>>& req) {
        vector<int>blocks(n, 0);
        solve(n, req, blocks, 0,0);
        return ans;
    }
};