class Solution {
public:
    bool solve(vector<int>&arr, int idx, vector<int>&dp, vector<int>&vis)
    {
        if(idx < 0 || idx >= arr.size())
            return false;
        if(arr[idx] == 0)
            return true;

        if(dp[idx] != -1) 
            return dp[idx];
        bool ans = false;
        
        if(arr[idx] + idx < arr.size() && !vis[arr[idx]+idx]) {
            vis[arr[idx] + idx] = 1;
            ans |= solve(arr, arr[idx] + idx, dp, vis);
            vis[arr[idx] + idx] = 0;
        }
        
        if(idx - arr[idx] >= 0 && !vis[idx - arr[idx]]) {
            vis[idx- arr[idx]] = 1;
            ans |= solve(arr, idx - arr[idx], dp, vis);
            vis[idx - arr[idx]] = 0;
        }

        return dp[idx] = ans;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<int>dp(n+1,-1);
        vector<int>vis(n+1,0);

        return solve(arr, start, dp, vis);
    }
};