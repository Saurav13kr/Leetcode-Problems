class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        int n=s.size();
        
        reverse(rev.begin(),rev.end());
        string s_new=s+'#'+rev;
        int n_new=s_new.size();
        vector<int> lps(n_new,0);
        int prev=0,i=1;
        
        while (i<n_new){
            if (s_new[i]==s_new[prev]){
                lps[i]=prev+1;
                prev++;
                i++;
            }
            else if (prev==0) lps[i++]=0;
            else if (prev>0)
                prev=lps[prev-1];
        }
        return rev.substr(0,n-lps.back())+s;
    }
};