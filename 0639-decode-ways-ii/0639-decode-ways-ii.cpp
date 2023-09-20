class Solution {
public:
    int numDecodings(string s) {
        long long mod = 1e9+7;
        int n=s.size();
        vector<long long> ans(n+1, 0);
        ans[n] = 1;

        for(int i=n-1; i>=0; i--) {
            if(s[i] == '0')
                ans[i] = 0;
            else if(s[i] == '*') {
                ans[i]+= 9*ans[i+1];    
                if(i<n-1) {
                    if(s[i+1] == '*') {
                        ans[i]+= 15*ans[i+2];
                    } 
                    else if(s[i+1] <= '6') {
                        ans[i]+= 2*ans[i+2];
                    } 
                    else {
                        ans[i]+= ans[i+2];
                    }
                }
            }
            else {
                ans[i] = (ans[i+1] % mod)%mod;

                if(i<n-1) {
                    if(s[i] == '1') {
                        if(s[i+1] == '*') {
                            ans[i] += 9*ans[i+2];
                        } 
                        else {
                            ans[i] += ans[i+2];
                        }
                    } 
                    else if(s[i] == '2') {
                        if(s[i+1] == '*') {
                            ans[i] += 6*ans[i+2];
                        } else if(s[i+1] <= '6'){
                            ans[i] += ans[i+2];
                        }
                    }
                }
            }

            ans[i] %= mod;
        }
        return ans[0];
    }
};