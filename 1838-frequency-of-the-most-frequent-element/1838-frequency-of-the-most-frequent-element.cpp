class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        int l = nums.size();
        int ans = 0;
        long long sum = 0;
        int left = 0;

        for (int right = 0; right < l; ++right) {
            sum += nums[right];

            int size = right - left + 1;

            while ((long long)nums[right] * size - sum > k) {
                sum -= nums[left];
                ++left;
                --size;
            }

            ans = max(ans, size);
        }

        return ans;
    }
};