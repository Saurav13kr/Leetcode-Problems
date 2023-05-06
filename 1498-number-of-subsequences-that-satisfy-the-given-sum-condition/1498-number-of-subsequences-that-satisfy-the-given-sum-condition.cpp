class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, b = nums.size(), a = 0, s = b-1, mod = 1e9+7;
        vector<int> pows(b, 1);
        
        for (int i = 1; i<b; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        
        while (a<=s) {
            if (nums[a] + nums[s] > target) {
                s--;
            } 
            else {
                res = (res + pows[s - a++]) % mod;
            }
        }
        
        return res;
    }
};