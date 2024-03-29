class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        long long ans = 0;
        int l=0,r=0;
        int cnt = 0;

        while(r<n){
            cnt += nums[r]==maxi;
            while(cnt>=k){
                ans += n-r;
                cnt -= nums[l++]==maxi;
            }
            r++;
        }

        return ans;
    }
};