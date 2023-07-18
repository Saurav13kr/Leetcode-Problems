class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true; 
        int start = 1, end = num-1; 
        
        while(start<=end){
            int mid = (start+end)/2;
            if(1ll * mid * mid == num) return true; 
            else if(1ll *mid*mid > num) end = mid-1; 
            else start = mid+1;
        }

        return false; 

    }
};