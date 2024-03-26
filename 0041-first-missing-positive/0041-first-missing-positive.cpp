class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<long ,int>mp;
        long maxi=INT_MIN;
        if(nums.size()==1 && nums[0]>1){
            return 1;
        }
        if(nums.size()==1 && nums[0]<0){
            return 1;
        }
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(nums[i]>maxi)maxi=nums[i];
        }
        if(maxi<0){
            return 1;
        }
        for( long i=1;i<=maxi+1;i++){
            if(mp[i]==0)return i;
        }
        return -1;
    }
};