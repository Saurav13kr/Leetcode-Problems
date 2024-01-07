#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];
 
                int sum = dp[j].count(diff) ? dp[j][diff] : 0;
    
                dp[i][diff] += sum + 1;
                result += sum;
            }
        }
        return result;
    }
};