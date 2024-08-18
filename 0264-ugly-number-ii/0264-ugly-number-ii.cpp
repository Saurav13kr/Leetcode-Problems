class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;

        vector<int> uglyNums(n);
        uglyNums[0] = 1;  // First ugly number is 1
        int i2 = 0, i3 = 0, i5 = 0;  // Indices for 2, 3, 5
        int next_multiple_of_2 = 2;
        int next_multiple_of_3 = 3;
        int next_multiple_of_5 = 5;

        for(int i = 1; i < n; i++) {
            int next_ugly = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
            uglyNums[i] = next_ugly;

            if(next_ugly == next_multiple_of_2) 
            {
                i2++;
                next_multiple_of_2 = uglyNums[i2] * 2;
            }
            if(next_ugly == next_multiple_of_3) {
                i3++;
                next_multiple_of_3 = uglyNums[i3] * 3;
            }
            if(next_ugly == next_multiple_of_5) {
                i5++;
                next_multiple_of_5 = uglyNums[i5] * 5;
            }
        }
        return uglyNums[n-1];
    }
};