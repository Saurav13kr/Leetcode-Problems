class Solution {
public:
    int hIndex(vector<int>&nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int a=0;
        int b=nums.size()-1;
        int n=nums.size();
        
        while(a<=b){
            int mid=(a+b)/2;
            if(nums[mid]==n-mid){
               
                ans=max(ans,n-mid);
                return ans;
            }
            
            else if(nums[mid]>n-mid){
                ans=max(ans,n-mid);
                b=mid-1;

            }
            
            else{
                a=mid+1;

            }
        }
        return ans;

    }
};