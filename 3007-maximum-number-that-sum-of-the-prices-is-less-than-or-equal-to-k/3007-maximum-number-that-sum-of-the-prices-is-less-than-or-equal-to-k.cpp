class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long l = 0, u = 1e17, m = (l+u)/2;
        long long ans;
        while( l<=u ){
            if( isValid(m, k, x) ){
                ans = m;
                l = m+1;
            } else{
                u = m-1;
            }
            m = (l+u)/2;
        }
        return ans;
    }

    bool isValid(long long num, long long k, long long x){
        long long priceSum = 0;
        for(int i=x;i<=60;i+=x){
            long long pairSize = ((long long)1<<i);
            long long ones = pairSize/2;
            long long price = 0;
     
            price += ((num+1) / pairSize)*ones;
         
            long long rem = ((num+1) % pairSize);
            price += (rem > ones)? (rem % ones) : 0;
            if( (k-price) < priceSum ) return false; 
            priceSum += price;
        }
        return true;
    }
};