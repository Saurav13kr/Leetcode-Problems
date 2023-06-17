class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0, n= ratings.size();
        
        vector<int>f(n,1);
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1])
                f[i]=f[i-1]+1;
        }

        vector<int> h(n,1);
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i]>ratings[i+1])
                h[i] = h[i+1]+1;
        }

        for(int i=0; i<n; i++) {
            ans += max(f[i], h[i]);
        }
        
        return ans;
    }
};