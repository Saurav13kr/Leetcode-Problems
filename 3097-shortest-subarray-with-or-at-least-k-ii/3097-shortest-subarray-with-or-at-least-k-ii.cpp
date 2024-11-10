class Solution {
public:
    void updateBitCount(vector<int>& bitCount, int val, bool add) {
        for (int i = 0; i < 32; ++i) {
            if (val & (1 << i)) {
                bitCount[i] += add ? 1 : -1;
            }
        }
    }
    int calculateBitwiseOr(const vector<int>& bitCount) {
        int result = 0;
        for (int i = 0; i<32; i++) {
            if (bitCount[i] > 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        vector<int> bitCount(32, 0);
        int n = nums.size();
        int minLength = INT_MAX;
        int left = 0, right = 0;
        
        while (right < n) {
            if(k==0 || nums[right]>=k)return 1;
            updateBitCount(bitCount, nums[right], true);
            while (left <= right && calculateBitwiseOr(bitCount) >= k) {
                minLength = min(minLength, right - left + 1);
                updateBitCount(bitCount, nums[left], false);
                left++;
            }
            right++;
        }
        
        return minLength == INT_MAX ? -1 : minLength;
    }
};