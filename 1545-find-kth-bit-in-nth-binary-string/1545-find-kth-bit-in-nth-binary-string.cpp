class Solution {
    int solve(int len, int k) {
        if(len == 1) return 0;
        int mid = (len + 1) >> 1; 
        if(k == mid) return 1;
        
        else if(k < mid) return solve(mid - 1, k);
        else return 1 - solve(mid - 1, len - k + 1);
    }
    
public:
    char findKthBit(int n, int k) 
    {
        return '0' + solve((1 << n) - 1, k);
    }
};