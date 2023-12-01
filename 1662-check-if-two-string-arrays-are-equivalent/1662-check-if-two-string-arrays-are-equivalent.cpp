class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="",s2="";
        for(int i=0;i<word1.size();i++){
            for(int j : word1[i]){
                s1 += j;
            }
        }
        for(int i=0;i<word2.size();i++){
                for(int j : word2[i]){
                    s2 += j;
                }
            }
        if(s1 == s2){
            return true;
        }
        else{
            return false;
        }
    }
};