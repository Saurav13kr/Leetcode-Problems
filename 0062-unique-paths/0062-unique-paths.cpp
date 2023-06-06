class Solution {
public:
    int uniquePaths(int a, int b) {
        int B = b + a - 2; 
        int r = min(b, a) - 1; 
        double res = 1;
        
        for(int i = 1; i <= r; i++, B--) {  
            res = res * (B) / i;
        }
        
        return (int)res;
    }
};