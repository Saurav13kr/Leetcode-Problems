class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
    }

    int maxSubarrayLength(vector<int>& nums, int k) {
        // Declare an unordered_map to store frequency of elements
        unordered_map<int, int> mp;
        int n = nums.size();
        int l = 0, r = 0, cnt = 0; // Initialize left pointer, right pointer, and counter

        while (r < n) {
            int cur = nums[r++];
            mp[cur]++; // Increment frequency of current element
            while (l < r && mp[cur] > k) {
                mp[nums[l++]]--; // Decrement frequency of leftmost element and move left pointer
            }

            cnt = max(cnt, r - l); // Update the maximum length of subarray
        }

        return cnt;
    }
};