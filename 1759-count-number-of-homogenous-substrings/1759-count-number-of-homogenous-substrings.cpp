class Solution {
public:
long long  mod=1e9+7;
    int countHomogenous(string s) {
        stack<char>st;
        long long n=0;
        int m=s.size();
        st.push('X');
        
        for(int i=0;i<=m;i++){
            if(st.top()!=s[i]|| i==s.size()){
                n+=st.size()*(st.size()+1)/2;
                while(st.size()!=0){
                    st.pop();
                }
                if(i<m)st.push(s[i]);
            }else{
                st.push(s[i]);
            }
        }
        return (n-1)%mod;
    }
};