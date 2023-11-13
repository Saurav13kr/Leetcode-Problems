class Solution {
public:
    string sortVowels(string s) {
        string temp="";

        for(int i=0;i<s.size();i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'|| s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
                temp+=s[i];
            }
        }

        sort(temp.begin(),temp.end());
         
         int j=0;
         for(int i=0;i<s.size();i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'|| s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
                s[i]=temp[j++];
            }
        }

        return s;
    }
};