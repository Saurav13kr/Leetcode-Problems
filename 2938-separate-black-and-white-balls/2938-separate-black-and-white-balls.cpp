class Solution {
public:
    long long minimumSteps(string s) 
    {
        long long n=s.size();
        long long ans=0;
        long long i=0,j=n-1;
        long long curr=0;
        
        for(int i=0;i<n;++i)
        {
            if(s[i]=='0')
            {
                ans+=(i-curr);
                curr++;
            }
        }
        return ans;
    }
};