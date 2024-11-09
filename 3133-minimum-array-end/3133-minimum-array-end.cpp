class Solution {
public:
    bool solve(int num)
    {
        return (ceil(log2(num))==floor(log2(num)));
    }
    void fill(int num, vector<int>&res)
    {
        int id = res.size()-1;
        while(num)
        {
            int rem = num%2;
            res[id--] = rem;
            num/=2;
        }
    }
    long long minEnd(int n, int x) 
    {
        if(n==1)
        {
            return x;
        }
        --n;
        int nbits = solve(n) ? log2(n)+1 : ceil(log2(n));
        int xbits = solve(x) ? log2(x)+1: ceil(log2(x));
        vector<int>xres(xbits,0);
        fill(x,xres);
        vector<int>nres(nbits,0);
        fill(n,nres);
        int i = xbits-1;
        int j = nbits-1;
        while(i>=0 && j>=0)
        {
            while(i>=0 && xres[i]==1)
            {
                i--;
            }
            if(i>=0 && xres[i]==0)
            {
                xres[i] = nres[j];
                j--;
                i--;
            }
        }

        while(j>=0) {
            xres.insert(xres.begin()+0,nres[j]);
            j--;
        }
    
        int c = 0;
        long long ans = 0;
    
        for(int i=xres.size()-1;i>=0;i--)
        {
            if(xres[i])
            {
                ans+=pow(2,c);
            }
            c++;
        }
        return ans;
    }
};