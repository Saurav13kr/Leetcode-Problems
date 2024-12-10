class Solution {
public:
    int maximumLength(string s) {
        map<string,int> mp;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(temp.length()==0 || temp[temp.length()-1]==s[i]){
                temp.push_back(s[i]);
            } else{
                mp[temp]++;
                if(temp.length()>1){
                    temp.pop_back();
                    mp[temp]=mp[temp]+2;
                }
                if(temp.length()>1){
                    temp.pop_back();
                    mp[temp]=mp[temp]+3;
                }
                temp="";
                temp.push_back(s[i]);
            }
        }
        if(temp.length()>0){
            mp[temp]++;
                if(temp.length()>1){
                    temp.pop_back();
                    mp[temp]=mp[temp]+2;
                }
                if(temp.length()>1){
                    temp.pop_back();
                    mp[temp]=mp[temp]+3;
                }
        }
            int maxlength=0;
            for(auto it : mp)
            {
                if(it.first.length()>maxlength && it.second>=3){
                    maxlength=it.first.length();
                    cout<<it.first<<" , ";
                }
            }
            if(maxlength==0){
                return -1;
            }
            return maxlength;
    }
};