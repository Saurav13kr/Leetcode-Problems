class Solution {
public:
    string mergeAlternately(string w1, string w2) {     
        string str;
        int i = 0, s1 = w1.length(), s2 = w2.length();
        
        while(i < s1 && i < s2){
            str.push_back(w1[i]);
            str.push_back(w2[i]);
            i++;
        }

        while(i < s1) {
            str.push_back(w1[i]);
            i++;
        }
        
        while(i < s2) {
            str.push_back(w2[i]);
            i++;
        }
        return str;
    }
};
