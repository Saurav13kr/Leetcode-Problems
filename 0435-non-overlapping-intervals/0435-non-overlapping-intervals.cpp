class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>&v) {
        sort(v.begin(),v.end());
        int count=0,l=0,r=1,n=v.size();
        
        while(r<n) {
            if(v[l][1]<=v[r][0]){
                l=r;
                r++;
            }
            
            else if(v[l][1]<=v[r][1]){
                count++;
                r++;
            }
            
            else if(v[l][1]>v[r][1]){
                count++;
                l=r;
                r++;
            }
        }
        return count;
    }
};