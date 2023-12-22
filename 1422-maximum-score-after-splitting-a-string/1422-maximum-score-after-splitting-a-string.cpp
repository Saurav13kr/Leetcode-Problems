class Solution {
public:
    int maxScore(string s) {
        int ans = INT_MIN;
        int zero = 0;
        int one = 0;
        
        for(auto i : s) {
            if(i == '1') one++;
        }
        
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == '0') zero++;
            else one--;
            ans = max(ans,one + zero);
        }

        return ans;
    }
};