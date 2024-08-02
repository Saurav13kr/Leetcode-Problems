class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=0; 
        int n = nums.size();

        for(auto &i:nums){
            if(i==1) k++;
        }

        if (k == 0) return 0; 

        int cnt_1=0; 
        int j=0;

        while(j<k)
        {
            if(nums[j]==1)
            {
                cnt_1++;
            }
            j++;
        }

        int maxi = cnt_1;

        for(int i=k;i<n+k;i++){
            if(nums[(i-k)%n]==1){
                cnt_1--;
            }

            if(nums[i%n]==1){
                cnt_1++;
            }

            maxi = max(maxi,cnt_1);
        }
        return k-maxi;
    }
};