class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = size(nums), i = 0, mn = INT_MAX, mx = INT_MIN, mnIdx = INT_MIN, mxIdx = INT_MIN;
        long long ans = 0;

        for(int j = 0; j < n; ++j) {
            if(nums[j] < minK || nums[j] > maxK) {
                mn = INT_MAX;
                mx = INT_MIN;
                mxIdx = INT_MIN;
                mxIdx = INT_MIN;
                i = j + 1;
                continue;
            }
            
            if(nums[j] == minK) {
                mn = nums[j];
                mnIdx = max(mnIdx, j);
            }
            if(nums[j] == maxK) {
                mx = nums[j];
                mxIdx = max(mxIdx, j);
            }

            if(mn == minK && mx == maxK)
                ans += (long long)(mnIdx < mxIdx ? mnIdx - i : mxIdx - i) + 1;
        }

        return ans;
    }
};