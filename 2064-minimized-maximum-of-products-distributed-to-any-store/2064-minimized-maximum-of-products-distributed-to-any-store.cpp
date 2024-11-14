class Solution {
public:
    bool valid_Qauntities(int n,vector<int>&quantities,int mid){
        int m = quantities.size();
        int cnt = 0;
        for(int i = 0; i<m; i++){
            int curr = quantities[i];
            cnt += (curr/mid + (curr%mid ? 1:0));
        }

        return cnt<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int m = quantities.size();
        int mx = 0;
        for(int i = 0; i<m; i++){
            mx = max(mx,quantities[i]);
        }
        int lo = 1, hi = 1e5;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            if(valid_Qauntities(n,quantities,mid))
            {
                hi = mid-1;
                ans = mid;
            }
            else{
                lo = mid+1;
            }
        }

        return ans;
    }
};