class Solution {
public:
    vector<int> prefix(string& w, string& r)
    {
        string s = w + '#' + r;
        int n = w.length(), m = s.length();
        vector<int> pi(m);
        for (int i = 1; i < m; i++)
        {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }

        return pi;
    }

    void storePairs(int i, string w, string r
                         , unordered_map<string, int>& m
                         , vector<vector<int>>& ans, bool rev)
    {
        int n = w.length();
        if (n == 0)
            return;
        
        vector<int> pi = prefix(w, r);

        // traverse prefix palindromes
        for (int l = pi[pi.size() - 1]; l > 0; l = pi[l - 1])
        {
            string s = l == n ? "" : w.substr(l, n - l);

            if (!rev)
                reverse(s.begin(), s.end());
            
            if (m.count(s) && m[s] != i)
            {
                if (rev)
                    ans.push_back({i, m[s]});  // insert suffix
                else
                    ans.push_back({m[s], i});  // insert prefix
            }
        }

        // l = 0
        if (m.count(r) && m[r] != i)
        {
            if (rev)
                ans.push_back({i, m[r]});
            else
                ans.push_back({m[r], i});
        }
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++)
            m[words[i]] = i;

        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
        {
            string w, r;
            w = r = words[i];
            reverse(r.begin(), r.end());
            
            storePairs(i, w, r, m, ans, false);  // insert prefix
            storePairs(i, r, w, m, ans, true);   // insert suffix
        }

        return ans;
    }
};