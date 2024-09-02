class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
         long long ans=0;
         long long sum=accumulate(chalk.begin(),chalk.end(),0LL);
         long long  curchalk=k%sum;
        for(int i=0;i<n;i++)
        {
             long long reqchalk=chalk[i];
            if(curchalk<reqchalk){
                ans=i;
                break;
            }
            curchalk-=reqchalk;
        }
        return ans;
    }
};