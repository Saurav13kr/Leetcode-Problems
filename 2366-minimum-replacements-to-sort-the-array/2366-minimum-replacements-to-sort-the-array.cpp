class Solution {
public:
    long long minimumReplacement(vector<int>& nums){
        int n=nums.size();
        long long count=0;
        long long maxi=nums[n-1];
        
        for(int i=n-2;i>=0;i--) {
           if(maxi<nums[i]) {
            long long val=ceil((nums[i]*1.0)/maxi);
               
            maxi=nums[i]/val;
            count+=val-1;
           } else {
               maxi=nums[i];
           }
          
        }    
        return count;
    }
};