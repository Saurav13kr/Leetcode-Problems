class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems){
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i] = m++;
            }
        }

        unordered_set<int> ig[n]; 
        unordered_set<int> gg[m];       
        for(int i=0;i<n;i++){
            int to_grop = group[i]; 
            for(auto it:beforeItems[i]){
                int from_group = group[it]; 
                if(to_grop!=from_group){
                    gg[from_group].insert(to_grop);
                }
                ig[it].insert(i);
            }
        }
        
        vector<int> ordered_items = topo(ig,n);
        vector<int> ordered_groups = topo(gg,m);
        
        map<int,vector<int>> elems_of_grp;
    
        for(auto it:ordered_items){
            cout << it << " ";
            elems_of_grp[group[it]].push_back(it);
        }
        cout << endl;

        vector<int> ans;
        for(auto it:ordered_groups){
            cout << it << " ";
           for(auto el:elems_of_grp[it]){
            ans.push_back(el);   
           }
        }
        return ans;
    }

  vector<int> topo(const unordered_set<int> g[],int n) {
    int k = n;
    int cnt = n;
    vector<int> indeg(k), res;
    for(int i = 0; i < k; i ++)
        for(int v : g[i]) indeg[v] ++;

    queue<int> q;
    for(int i = 0; i < k; i ++)
        if(indeg[i] == 0) q.push(i);

    while(!q.empty()) {
        int i = q.front(); 
        res.push_back(i);
        cnt--;
        q.pop();
        for(int x : g[i])
            if(--indeg[x] == 0) q.push(x);
    }
    return cnt==0?res:vector<int>{};
}
};