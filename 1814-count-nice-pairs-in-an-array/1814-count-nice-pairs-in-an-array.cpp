class Solution {
    int MOD = 1e9 + 7;

    int rev(int num) {
        int res = 0;
        while (num > 0) {
            int curr = num % 10;
            res = res * 10 + curr;
            num /= 10;
        }
        return res;
    }

public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int reversed = rev(nums[i]);
            mp[nums[i] - reversed]++;
        }

        long count = 0;

        for (auto i : mp) {
            long curr = i.second;
            count += (curr * (curr - 1)) / 2;
            count %= MOD;
        }

        return count;
    }
};