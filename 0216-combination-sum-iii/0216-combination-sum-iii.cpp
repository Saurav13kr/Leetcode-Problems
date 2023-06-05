class Solution {
public:
    
    vector<vector<int>> s;
    void f(vector<int>& r, int c, int b, int n) {
        if(n<0 || r.size()>b) return;
        if(n==0 && r.size() == b) {
            s.push_back(r);
            return;
        }
        
        for(int i=c; i<=9; i++) {
            r.push_back(i);
            f(r, i+1, b, n-i);
            r.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int b, int n) {
        vector<int> r;
        f(r,1,b,n);
        
        return s;
    }
};