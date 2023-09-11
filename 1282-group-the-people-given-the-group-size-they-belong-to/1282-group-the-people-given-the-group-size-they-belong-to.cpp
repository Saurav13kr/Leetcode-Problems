class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>>ans;
        vector<int>arr[n+1];
        for(int i=0;i<n;i++){
            if(groupSizes[i]==1) ans.push_back({i});
            else arr[groupSizes[i]].push_back(i);
        }
        
        for(int i=2;i<=n;i++){
            vector<int>v;
            for(int j:arr[i]){
                if(v.size()<i) v.push_back(j);
                else{
                    ans.push_back(v);
                    v.clear();
                    v.push_back(j);
                }
            }
            if(v.size()>=2)ans.push_back(v);
        }
    return ans;
    }
};