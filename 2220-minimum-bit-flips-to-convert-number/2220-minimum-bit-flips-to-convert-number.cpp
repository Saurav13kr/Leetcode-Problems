class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        while(goal!=0||start!=0) {
           
             if((start&1)^(goal&1)!=0)
             {
                ans++;
             }
             start=start>>1;
             goal=goal>>1;
        }
        return ans;
    }
};