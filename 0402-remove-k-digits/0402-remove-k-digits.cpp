class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        int target = num.size() - k;
        vector<char> st;
        for (auto x : num){
            while(k > 0 && !st.empty() && st[st.size() - 1] > x)
            {
                st.pop_back();
                k--;
            }
            st.push_back(x);
        }
        string ans = "";
        while(k){
            st.pop_back();
            k--;
        }
        for (char x : st)
        {
            if (ans.empty() && x == '0')
                continue;
            ans += x;
        }
        return ans.empty() ? "0" : ans;
    }
};