class Solution {
public:
    int largestSum(vector<int>& nums,int mid){
        int cntSubarr=1;
        int cntSum =0;
        
        for(int i=0;i<nums.size();i++) {
            if(cntSum+nums[i]<=mid){
                cntSum+=nums[i];
            }
            else{
                cntSubarr++;
                cntSum=nums[i];
            }
        }
        return cntSubarr;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        int l =*max_element(nums.begin(),nums.end());
        int r =accumulate(nums.begin(),nums.end(),0);
        int mid;
        
        while(l<=r){
            mid =(l+r)/2;
            if(largestSum(nums,mid)>k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};