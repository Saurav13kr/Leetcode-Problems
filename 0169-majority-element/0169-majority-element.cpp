class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int s = nums.size();
        sort(nums.begin(), nums.end());
        return nums[s/2];  
    }
};