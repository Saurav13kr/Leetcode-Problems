class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mpp;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==goal)
            {
                count++;
            }
            if(sum>=goal)
            {
                int rem=sum-goal;
                if(mpp.find(rem)!=mpp.end())
                {
                    count+=mpp[rem];
                }
            }
            mpp[sum]++;
        }
        return count;
    }
};