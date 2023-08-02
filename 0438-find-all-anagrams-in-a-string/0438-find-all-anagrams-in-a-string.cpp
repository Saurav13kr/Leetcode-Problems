class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        if(s.size() < p.size()) return {};
        
        vector<int> freq_p(26,0);
        vector<int> w(26,0);
        
        for(int i=0;i<p_len;i++){
            freq_p[p[i]-'a']++;
            w[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == w) ans.push_back(0);
        
        for(int i=p_len;i<s_len;i++) {
            w[s[i-p_len] - 'a']--;
            w[s[i] - 'a']++;
            
            if(freq_p == w) ans.push_back(i-p_len+1);
        }
        
        return ans;
    }
};