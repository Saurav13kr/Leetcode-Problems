class Solution {
public:
    int pivotInteger(int n) {
        int totsum=(n*(n+1))/2;

        int tempsum=0;
        for(int i=1;i<=n;i++){
            tempsum+=i;
            if(tempsum==(totsum-tempsum+i)){
                return i;
            }
        }
        return -1;
    }
};