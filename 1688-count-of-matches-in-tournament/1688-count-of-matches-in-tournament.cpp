class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n != 1){
            int rem = n / 2;
            ans += rem;
            n = n - rem;
        }
        return ans;
    }
};