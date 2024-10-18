class Solution {
public:

    int check(int i,int target,int pre,vector<int>& nums){
        if(i==nums.size())
        {
            if(target==pre)return 1;
            return 0;
        }
        int ans=0;
        ans+=check(i+1,target,pre,nums);
        ans+=check(i+1,target,pre|nums[i],nums);
        return ans;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int a=0;
        for(int i:nums)a=a|i;
        return check(0,a,0,nums);
    }
};