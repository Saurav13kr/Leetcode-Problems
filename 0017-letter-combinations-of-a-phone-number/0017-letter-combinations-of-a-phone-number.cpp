class Solution {
public:
    vector<string> a;
    string keyPad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    
    void backtrack(int n, string & p, const string& d) {
        if (n == d.size()) {
            a.push_back(p);
            return;
        }
        
        for (char c:keyPad[d[n]-'0']) {
            p[n] = c;
            backtrack(n+1, p, d);
        }
    }
    vector<string> letterCombinations(const string& d) {
        if (d.empty()) return a;
        string p = d;
        backtrack(0, p, d);
        
        return a;
    }
};