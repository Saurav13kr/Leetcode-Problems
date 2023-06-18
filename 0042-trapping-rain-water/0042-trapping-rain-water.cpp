class Solution {
    
public:
    int trap(vector<int>& h) {     
        int k=0, l=0, r = h.size()-1, level=0;
        
        while (l < r) {
            while (l < r && h[l] <= level)
                
                k += level - h[l++];
            
            while (l < r && h[r] <= level)
                
                k += level - h[r--];
            
            level = min(h[l], h[r]);
        }
        
        return k;
    }
};