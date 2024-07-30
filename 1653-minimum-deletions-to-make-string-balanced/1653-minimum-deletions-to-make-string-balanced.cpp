class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int>numB(n), numA(n);
        int cntB = 0, cntA = 0;
        for(int i = 0; i < n; i ++)
        {
            numB[i] = cntB;
            if(s[i] == 'b')cntB ++;
        }
        for(int i = n - 1; i >= 0; i --){
            numA[i] = cntA;
            if(s[i] == 'a')cntA ++;
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i ++)
        {
           ans = min(ans, numA[i] + numB[i]);
        }
        return ans;
    }
};