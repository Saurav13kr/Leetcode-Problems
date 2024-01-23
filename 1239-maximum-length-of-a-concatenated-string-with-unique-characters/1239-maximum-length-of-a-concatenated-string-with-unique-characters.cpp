class Solution {
public:
    bool ok(string s, string a) {
        set<char>st;
        for(auto it:s){
            st.insert(it);
        }
        
         for(auto it:a){
            st.insert(it);
        }
        
        return s.size()+a.size()==st.size();
    }
    
    int dfs(int i, vector<string>& arr, string s, int n, int& ans) {
        if (i == n)
            return 0;
        int take = 0;
        int notake = 0;
        
        if (ok(s, arr[i])) {
            take = (arr[i].size()) + dfs(i + 1, arr, s + arr[i], n, ans);
        }
        notake = dfs(i + 1, arr, s, n, ans);
        return max(take, notake);
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int ans = 0;
        return dfs(0, arr, "", n, ans);
    }
};