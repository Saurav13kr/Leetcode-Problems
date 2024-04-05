class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(ans.empty() || (ans.back() - s[i] != 32 && ans.back() - s[i] != -32)){
                ans.push_back(s[i]);
            } else{
                ans.pop_back();
            }
        }

        return ans;
    }
};