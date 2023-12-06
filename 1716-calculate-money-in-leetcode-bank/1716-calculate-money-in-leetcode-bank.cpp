class Solution {
public:
    int totalMoney(int n) {

        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
        { 
            if(i%7 == 0)    ans = ans+ 6 + i/7;
            else    ans += i/7 + i%7 ;
        }
            return ans;
    }
};