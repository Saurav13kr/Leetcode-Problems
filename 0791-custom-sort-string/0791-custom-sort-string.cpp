class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        
        unordered_map<char, int> m;
        for (auto i : s)
            m[i]++;

        for (char ch:order ) {
            while (m[ch] > 0) {
                    ans.push_back(ch);
                    m[ch]--;
                }
            }
        for (auto& i:m ) {
            while (i.second > 0) {
                    ans.push_back(i.first);
                    i.second--;
                }
            }
        return ans;
    }
};