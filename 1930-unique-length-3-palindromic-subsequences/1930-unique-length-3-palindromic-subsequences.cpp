class Solution {
public:
  int countPalindromicSubsequence(string s) {
        int pre[26] = {0} ;
        int post[26] = {0} ;
        int ans = 0 ;
        int n   = s.size() ;
        
        for( int i = 2 ; i < n ; i++ ){
            post[s[i]-'a']++ ;
        }
        
        pre[s[0]-'a']++ ;
        int dp[26][26] = {0} ;
        
        
        for( int i = 1 ; i < n - 1 ; i++ )
        {
            for(int j = 0 ; j < 26 ; j++ )
            {
                string temp = "" ;
                temp += char(j +'a') + s[i] + char(j +'a') ;
                
                if( pre[j] != 0 && post[j] != 0 && dp[s[i]-'a'][j] == 0 )
                {
                    ans++ ;
                    dp[s[i]-'a'][j]++ ;
                }
            }
            
            post[s[i+1]-'a']-- ;
            pre[s[i]-'a']++ ;
        }
        
        return ans ;
    
    }
};