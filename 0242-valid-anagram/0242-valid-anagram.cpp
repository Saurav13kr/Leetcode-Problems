class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        for(int i = 0; i < s.size(); i += 1){
            cnt[s[i] - 'a'] += 1;
        }
        for(int i = 0; i < t.size(); i += 1){
            cnt[t[i] - 'a'] -= 1;
        }
        return count(cnt.begin(), cnt.end(), 0) == 26;
    }
};