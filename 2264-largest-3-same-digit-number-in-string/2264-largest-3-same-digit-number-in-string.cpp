class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        string temp="";
        int a=-1;
    
        for(int i=0;i<num.size();i++){
            if(temp.size()==3){
               int b=stoi(temp);
               a=max(a,b);
               temp="";
               temp+=num[i];
            }
         else if(temp.size()==0){
                temp=temp+num[i];
            }
          else if(temp[temp.size()-1]!=num[i]){
                temp="";
                temp=temp+num[i];
            }
            else{
                temp+=num[i];
            }
        }
        if(temp.size()==3) {
            a=max(a,stoi(temp));
        }
        if(a==-1) return ans;
        if(a==0) return "000";
        return to_string(a);
    }
};