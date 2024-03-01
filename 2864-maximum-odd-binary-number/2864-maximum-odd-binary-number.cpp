class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end());

        string ans="";
        for(int i=s.size()-2; i>=0; i--){
            ans += s[i];
        }
        ans += '1';

        return ans;
    }
};