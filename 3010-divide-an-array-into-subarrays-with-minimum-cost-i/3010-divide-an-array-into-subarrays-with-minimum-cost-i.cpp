class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int>ans = nums;
        sort(ans.begin(),ans.end());
        
        if(nums[0]==ans[0]){
            return nums[0]+ans[1]+ans[2];
        }
        
        if(nums[0]==ans[1]){
            return nums[0]+ans[0]+ans[2];
        }
        
        return nums[0]+ans[0]+ans[1];
    }
};