class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        vector<int>res(nums.size());
        int tXor=0;
         int n=nums.size();
       
        int maxima=pow(2,maximumBit)-1;
        for(int i=1;i<=nums.size();i++) {
             tXor^=nums[i-1];
            res[n-i]=(tXor^maxima);
           
        }
        return res;

    }
};