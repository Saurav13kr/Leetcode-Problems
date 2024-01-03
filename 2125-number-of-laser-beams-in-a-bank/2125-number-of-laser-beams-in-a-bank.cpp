class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m  = bank.size();
        int n = bank[0].size();
        int prev = 0;
        int ans = 0;
        for(int i=0;i<m;i++){
            int curCount = 0;
            for(int j=0;j<n;j++){
                if(bank[i][j]=='1') curCount++;
            }
            if(prev!=0 && curCount!=0){
                ans+= prev*curCount;
            }
            if(curCount!=0)prev = curCount;
        }

        return ans;
    }
};