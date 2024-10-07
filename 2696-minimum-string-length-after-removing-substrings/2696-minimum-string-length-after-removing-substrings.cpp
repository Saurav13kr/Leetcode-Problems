class Solution {
public:
    int minLength(string s) {
        for (int i=0;i<s.size();i++){
            if (s[i]=='A' && s[i+1]=='B'|| s[i]=='C' && s[i+1]=='D')
            {
                s = s.substr(0,i) + s.substr(i+2);
                i = -1;
            }
        }
        return s.size();
    }
};