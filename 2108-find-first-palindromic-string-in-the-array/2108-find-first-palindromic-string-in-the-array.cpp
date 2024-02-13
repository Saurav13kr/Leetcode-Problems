class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int f=1;
        for(int i=0;i<words.size();i++)
        {
            f=1;
            for(int j=0;j<words[i].size()/2;j++)
            {
                if(words[i][j]!=words[i][words[i].size()-1-j]){
                    f=0;break;
                }
            }
            if(f==1) return words[i];
        }
        return "";
    }
};