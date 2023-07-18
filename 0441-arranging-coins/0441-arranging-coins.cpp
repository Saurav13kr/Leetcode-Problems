class Solution {
public:
    int arrangeCoins(int n) {

        if(n == 0 || n == 1) return n;

        long long left = 0;
        long long right = n;

        while(left <= right){
            long long mid = left + (right - left)/2;

            if(n >= (mid * (mid+1))/2) left = mid +1;
            else right = mid - 1;
        }

        return left - 1;
    }
};