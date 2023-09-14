class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<string>>a;
        map<string,vector<int>>b;
        int i=0,n=tickets.size();
        for(i=0;i<tickets.size();i++)
            a[tickets[i][0]].push_back(tickets[i][1]);
        for(auto it=a.begin();it!=a.end();it++)
        {
            sort(it->second.begin(),it->second.end());
            vector<int>c(it->second.size(),0);
            b[it->first]=c;
        }
        vector<string>d;
        dfs(a,b,d,d,"JFK",n);
        return d;
    }
    void dfs(map<string,vector<string>>a, map<string,vector<int>>b, vector<string>r, vector<string>& d, string s, int n)
    {
        if(d.size()>0) return;
        r.push_back(s);
        if(r.size()==n+1)
        {
            d=r;
            return;
        }
        int i=0;
        for(i=0;i<a[s].size();i++)
            if(b[s][i]==0)
            {
                b[s][i]=1;
                dfs(a,b,r,d,a[s][i],n);
                b[s][i]=0;
            }
        return;
    }
};