class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& b, int k) {
        vector<int> d(n,-1);
        set<int> s;
        for(int i : b) s.insert(i);
        queue<int> q;
        map<int,bool> vis;
        vis[p] = true;
        q.push(p);
        int dis = 0;
        vector<set<int>> vs(2);
        for(int i = 0; i < n; i++) {
            vs[i % 2].insert(i);
        }
        for(int j : b) {
            vs[j % 2].erase(j);
        }
        vs[p % 2].erase(p);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int a = q.front();
                q.pop();
                d[a] = dis;
                int mn = max(0, a - k + 1);
                int y = a - mn;
                int j = mn + (k - 1 - y);
                int p = j;
                vector<int> v;
                int mx = mn + k - 1;
                
                for(auto k1 = vs[j % 2].lower_bound(j); k1 != vs[j % 2].end() && *k1 <= (a + k - 1) && (mx + ((*k1 - p) / 2) < n); k1++) {
                    if(vis[*k1] == false) {
                        vis[*k1] = true;
                        q.push(*k1);
                        v.push_back(*k1);
                    }
                }          
                for(int i : v) {
                    vs[i % 2].erase(i);
                }
            }
            dis++;
        }
        return d;
    }
};