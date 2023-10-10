class Solution {
public:
    int minOperations(vector<int>& a) {
        sort(a.begin(),a.end());
        int n = (int)a.size();
        int c = n-1;
        int dup = 0;
        vector<int>pref(n+1,0);
        
        for(int i = 0 ; i < n ; i++) {
            if(i > 0 && a[i] == a[i-1]) {
                pref[i+1]++;
            }

        }
        for(int i = 1 ; i <= n ; i++) {

            pref[i] += pref[i-1];

        }
        
        for(int i = 0 ; i < n ; i++) {
            int p = lower_bound(a.begin(),a.end(),a[i]+n) - a.begin();
            int remove = n-1 - p + 1 + i;
            dup = pref[p] - pref[i]; 
            c = min(c,remove + dup);

        }
        return c;
    }
};