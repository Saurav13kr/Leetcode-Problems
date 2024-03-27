class Solution {
public:

    int check_mul(vector<int>& nums, int k, int &left, long long int &prod) {
        int n=nums.size(),right=left,c=0;

        while(right < n) {
            prod *= nums[right];
            if(prod < k) c++;
            else {
                left++;
                right=left-1;
                prod=1;
            }

            right++;
        }

        return c;
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0, n=nums.size(), left=0;

        long long int prod=1;

        ans += check_mul(nums,k,left,prod);

        if(left==n-1) return ans;

        int num = n-left-1;

        ans += (num*(num+1))/2;

        return max(ans,0);
    }
};