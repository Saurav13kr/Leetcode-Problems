typedef pair<int,int> PII;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size(), m = queries.size();
        vector<PII> intervals;
        vector<bool> ans(m, false);

        auto checkParity = [](int a, int b){
            if((a % 2 == 1 && b % 2 == 1) || (a % 2 == 0 && b % 2 == 0))
                return false;
            return true;
        };

        for(int i = 1, j = 0; i <= n; i++)
        {
            if(i == n || checkParity(nums[i], nums[i - 1]) == false)
            {
                intervals.push_back({j, i - 1});
                j = i;
            }
        }


        for(int i = 0; i < m; i++) {
            auto ind = upper_bound(intervals.begin(), intervals.end(), queries[i][0], [](int val, PII &interval){
                return val < interval.first;
            }) - intervals.begin();
            
            ind--;
            
            if(ind >= 0 && intervals[ind].first <= queries[i][0] && intervals[ind].second >= queries[i][1])
                ans[i] = true;
        }

        return ans;
    }
};