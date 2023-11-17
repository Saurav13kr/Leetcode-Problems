class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int s=0,e=n-1;
        int ans = -1;
        
        while(s<e){
            int sum = nums[s]+nums[e];
            if(sum>ans){
                ans=sum;
            }
            s++;
            e--;
        }
        return ans;
    }
};