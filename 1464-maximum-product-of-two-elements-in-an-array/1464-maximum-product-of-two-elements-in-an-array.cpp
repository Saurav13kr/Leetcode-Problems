class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int maxii = 0;

        for ( int i=1; i<nums.size(); i++ ) {

            if ( nums[i] >= maxi ) {
                maxii = maxi;
                maxi = nums[i];
            }

            else {
                maxii = max(maxii,nums[i]);
            }
        }

        return (maxi-1)*(maxii-1);
    }
};