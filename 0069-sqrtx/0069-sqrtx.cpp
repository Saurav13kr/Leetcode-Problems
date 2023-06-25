class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return x;
        int first = 1, last = x;
        
        while (first <= last) {
            int m = first + (last - first) / 2;
            if (m  == x / m)
                return m;
            
            else if (m > x / m) {
                last = m - 1;
            }
            
            else {
                first = m + 1;
            }
        }
        return last;
    }
};