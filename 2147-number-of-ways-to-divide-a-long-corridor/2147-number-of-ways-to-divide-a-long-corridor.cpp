class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int sof = 0, last=0, mod = 1000000000+7;
        long long int divd = 1;
        for ( int i=0; i<n; i++ )
        {
            if ( corridor[i] == 'S' ){
                sof++;
                if ( sof > 2 ){
                    divd = (divd*(i-last))%mod;
                    sof = 1;
                }
                last = i;
            }
        }
        
        return (sof == 0 || sof == 1 ? 0 : divd );
    }
};