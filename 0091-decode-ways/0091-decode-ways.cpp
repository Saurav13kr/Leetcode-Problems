class Solution {
public:
    int dp[101] ;
    int cal(int i , int n , string &s ){
        if((i==n-1 && s[i]!='0' )|| i==n )
            return 1  ; 
    
        if(dp[i]!=-1)
            return dp[i] ;
        
        int a= 0, b= 0; 
        if(s[i]>'0')
        a = cal(i+1, n , s ) ; 
        if(s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))
        b = cal(i+2, n ,s ) ;
        
        return dp[i] = a+b;
        
    }
    int numDecodings(string s) {
        if(s=="0")
            return 0 ; 
        if(s[0]=='0')
            return 0 ; 
        memset(dp, -1, sizeof(dp)); 
        return cal(0, s.length() ,s ) ;
    }
};