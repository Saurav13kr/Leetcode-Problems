class Solution {
public:
    int fourSumCount(vector<int>& p, vector<int>& q, vector<int>& r, vector<int>& s) {
        unordered_map<int, int> hash;
        int n = p.size();
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                hash[p[i] + q[j]]++;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans = ans + hash[-(r[i] + s[j])];
            }
        }
        
        return ans;
        
    }
};