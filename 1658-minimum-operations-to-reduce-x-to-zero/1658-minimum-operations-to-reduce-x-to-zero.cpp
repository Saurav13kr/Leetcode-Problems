class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = INT_MAX;
        vector<int> prefix(n + 1);
        
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            if(prefix[i] == x) ans = i;
        }
        int sum = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            int index = lower_bound(prefix.begin(), prefix.begin() + i, x - sum) - prefix.begin();
            if(prefix[index] == x - sum) {
                ans = min(ans, index + n - i);
            }
        }
        return ans == INT_MAX? -1: ans;
    }
};