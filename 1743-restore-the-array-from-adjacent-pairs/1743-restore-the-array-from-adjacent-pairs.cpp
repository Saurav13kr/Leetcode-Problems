class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ar) {
       unordered_map<int,vector<int>>mp;
       unordered_map<int,int>check;
       vector<int>ans;
       int n=ar.size();
        
       for(int i=0;i<n;i++)
       {
           int a=ar[i][0];
           int b=ar[i][1];
           if(a>b)swap(a,b);
           mp[a].push_back(b);
           mp[b].push_back(a);
       }
       int t;
        
       for(auto x:mp)
       {
           if(x.second.size()==1)//finding First element
           {
               ans.push_back(x.first);
               ans.push_back(x.second[0]);
               check[x.first]=1;
               check[x.second[0]]=1;
               t=x.first;
               break;
           }
       }
       mp.erase(t);
        
       while(1)
       {
           bool flag=false;
           auto x=mp[ans.back()];
           for(auto p:x)
           {
               if(check[p]==0)
               {
                   ans.push_back(p);
                   check[p]=1;
                   flag=true;
               }
           }
           if(!flag)break;
       }
       return ans;
    }
};