class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> conornot(n,0); 
        
        for(auto i: edges) {
            conornot[i[1]]=1; 
            
        }
        
        vector<int> res;
        for(int i=0;i<n;i++) {
            
            if( conornot[i]==0) {
                res.push_back(i); 
            }
        }
        return res;
    }
};