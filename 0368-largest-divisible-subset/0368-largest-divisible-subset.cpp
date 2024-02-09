class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        bitset<1001> mask;
        vector<pair<int,bitset<1001>>> dp(n + 1,{0,mask});
        sort(nums.begin(),nums.end());
        int maxi = -1; bitset<1001> solmask;

        for(int i = 0; i < n;i++) {
            mask[i] = 1;
            dp[i] = {1,mask};
            mask[i] = 0;
            for(int j = 0; j <i;j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j].first + 1 > dp[i].first) {
                        bitset<1001> currmask = dp[j].second;
                        currmask[i] = 1;
                        dp[i] = {dp[j].first + 1,currmask};
                    }
                }
                
            }
            if(dp[i].first > maxi) {
                maxi = dp[i].first;
                solmask = dp[i].second;
            }
        }
        vector<int> sol;
        for(int  i = 0; i < 1001 ;i++) {
            if(solmask[i] == 1) sol.push_back(nums[i]);
        }
        return sol;
    }
};