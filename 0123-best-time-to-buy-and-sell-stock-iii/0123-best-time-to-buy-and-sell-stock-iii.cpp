class Solution {
public:
    vector<int>a;
    int n;
    int dp[100000][2][3] ;
    int f(int i , int state , int count) {
        if(i==n) {
            return 0;
        }
        
        if(count==2) {
            return 0;
        }
        
        int &C = dp[i][state][count];
        if(C!=-1) {
            return C;
        }
        
        if(state ==  0) {
            int op1 = f(i+1 , 0 , count );
            int op2 = f(i+1 , 1 , count ) - a[i];
            return C =  max(op1,op2);
        }
        
        if(state == 1) {
            int op1 = f(i+1 , 1 , count);
            int op2 = a[i] + f(i+1 , 0 , count + 1 );
            return C =  max(op1, op2);
        }
        return  -1;
    }
    
    int maxProfit(vector<int>& a) {
        this->a = a;
        n = a.size();
        memset(dp, -1, sizeof dp);
        
        return f(0,0,0);
    }
};