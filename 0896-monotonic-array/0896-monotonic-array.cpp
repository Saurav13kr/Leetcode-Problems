class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1) return true;
        if(nums[0]>nums[n-1])
        reverse(nums.begin(),nums.end());
        
        for(int i=0;i<n-1;i++) 
        if(nums[i]>nums[i+1])
        return false;
        return true;
    }
};