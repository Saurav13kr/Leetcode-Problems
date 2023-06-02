class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp = s+s;
        tmp = tmp.substr(1);
        tmp = tmp.substr(0, tmp.length()-1);
        return tmp.find(s) != string::npos ? true : false;
    }
};