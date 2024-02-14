class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int numsSize = nums.size();

        vector<int>pnum;
        vector<int>nnum;

        for(int i=0;i<numsSize;i++)
        {
            if(nums[i] < 0)
            {
                nnum.push_back(nums[i]);
            } else {
                pnum.push_back(nums[i]);
            }
        }

        vector<int>res;

        for(int i=0;i<numsSize;i++)
        {
            if(i%2 == 0)
            {
                res.push_back(pnum[i/2]);
            }
            else
            {
                res.push_back(nnum[(i-1)/2]);
            }
        }

        return res;
    }
};