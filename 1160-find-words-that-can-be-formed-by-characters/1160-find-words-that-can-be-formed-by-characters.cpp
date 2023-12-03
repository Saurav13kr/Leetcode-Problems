class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       int n1 = words.size();
       int n2 = chars.size();
       int counter=0;
       map<char,int>mp;
        
       for(int i=0; i<n2;i++){
           mp[chars[i]]++;
       }
        
       for(int i=0; i<n1; i++){
           map<char,int>temp;
           int flag=0;
           
           for(int j=0; j<words[i].size();j++){
               temp[words[i][j]]++;
           }
           
           for(int j=0; j<words[i].size();j++){
               if(temp[words[i][j]] > mp[words[i][j]]){
                   flag=1;
               }
           }
           
           if(flag==0){
               counter = counter + words[i].size();
           }

       }
       return counter;
    }
};