class Solution {
public:
    int getSmallerCount(int m, int n, int x){
        int y, smallerCount = 0;
        for(int i = 1; i <= m; i++){
            y = x / i;
            if(x % i){
                smallerCount += (y > n) ? n : y;
            }else{
                smallerCount += ((y - 1) > n) ? n : (y - 1);
            }
        }
        return smallerCount;
    }

    int findKthNumber(int m, int n, int k) {
        int start = 1;
        int end = m * n;
        int mid;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(start == mid){
                if(getSmallerCount(m, n, end) < k){
                    return end;
                }else{
                    return start;
                }
            }else{
                if(getSmallerCount(m, n, mid) < k){
                    start = mid;
                }else{
                    end = mid;
                }
            }
        }
        return -1;
    }
};