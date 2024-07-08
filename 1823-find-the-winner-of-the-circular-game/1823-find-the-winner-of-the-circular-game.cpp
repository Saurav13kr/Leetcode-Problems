class Solution {
public:
    int findind(int n,int k)
    {
        if(n==1) return 0;
        int ind = findind(n-1,k);
        ind = (ind+k)%n;
        return ind;
    }
    int findTheWinner(int n, int k) {
        int idx = findind(n,k);
        return idx+1;  
    }
};