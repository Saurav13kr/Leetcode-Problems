class Solution {
public:
    
int dp[38];
  int fib1(int s){
      
      if(s == 0)return dp[s] = 0;
      if(s == 1 or s == 2)return dp[s] = 1;
     if(dp[s] != -1) return dp[s];
      return dp[s] = fib1(s-1) + fib1(s-2) + fib1(s-3);
  }
    
    int tribonacci(int s) {
        memset(dp, -1, sizeof(dp));
        return fib1(s);
    }
};