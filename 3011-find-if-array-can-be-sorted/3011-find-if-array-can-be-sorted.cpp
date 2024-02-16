class Solution {
    int num_bits(int n) {
        int ans = 0;
        for(int i = 0; i < 32 && n > 0; ++i) {
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
    void push_down(int idx, vector<int> &nums) {
        if(idx <= 0)
            return;
        int prev_bits = num_bits(nums[idx-1]);
        int curr_bits = num_bits(nums[idx]);
        if(prev_bits == curr_bits && nums[idx-1] > nums[idx]) {
            swap(nums[idx-1], nums[idx]);
            push_down(idx - 1, nums);
        }
    }
public:
    bool canSortArray(vector<int>& nums) {
        int N = nums.size();
        for(int i = 1; i < N; ++i) {
            push_down(i, nums);
        }
        
        return is_sorted(nums.begin(), nums.end());
    }
};