class Solution {
public:
    int solve(int i,vector<vector<int>>&job, vector<int>&startTime, int n, vector<int>&dp ){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int index=lower_bound(startTime.begin(),startTime.end(),job[i][1])-startTime.begin();
        int pick=job[i][2]+solve(index,job,startTime,n,dp);
        int notpick=solve(i+1,job,startTime,n,dp);
        return dp[i]=max(pick,notpick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        int m=endTime.size();
        int i,j,sum=0;
        vector<vector<int>>job;
        vector<int>dp(n,-1);
        for(i=0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        sort(startTime.begin(),startTime.end());
        return solve(0,job,startTime,n,dp);
        
    }
};