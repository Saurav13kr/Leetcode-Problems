class Solution {
public:
    int solve(string &s, string p, int val, int &ans) {
        vector<char>st;
        for(int i = 0; i < s.length(); i++) {
            if(!st.empty() && st.back() == p[0] && s[i] == p[1]) {
                st.pop_back();
                ans+=val;
            } else st.push_back(s[i]);
        }
        s = "";
        int i = 0;
        while(i < st.size()) {
            s += st[i];
            i++;
        }
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        string p = "", q = "";
        int val, val2;
        int ans = 0;
        
        if(x > y) 
        {
            p = "ab";
            q="ba";
            val = x;
            val2=y;
        } 
        else {
            p = "ba"; 
            val = y;
            q="ab";
            val2=x;
        }
        solve(s,p,val,ans);
        solve(s,q,val2,ans);
        return ans;
    }
};