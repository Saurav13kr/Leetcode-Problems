class Solution {
public:
string ans;
          void say(int n,string str,int num)
{
                if(n==num+1){
                ans=str;
                return ;
                }
              
                if(n==1)
                          
                    str="1";
                    say(n+1,str,num);
                    return;
                }
              
               string s;
               int cnt=1;
               char c=str[0];
               stack<char> st;
              
               for(int i=0;i<str.size();i++){
                if(!st.empty()&& st.top()==str[i]){
                    st.push(str[i]);
                }
                   
                else if(st.empty())
                st.push(str[i]);
                else{
                    s = s+to_string(st.size())+st.top();
                    while(!st.empty()) st.pop();
                    st.push(str[i]);
                }
            }
            if(!st.empty()){
                s=s+to_string(st.size())+st.top();
            }
               
                say(n+1,s,num);
            }

    string countAndSay(int n) {
       say(1,"",n);
        
       return ans;
    }
};
