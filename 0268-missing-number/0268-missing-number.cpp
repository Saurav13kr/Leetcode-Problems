class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();//getting size

        int sum  =( size * (size+1))/2; 

        for(int i=0 ; i<size ; i++)
        {
            sum-=nums[i];
    
        }
         
        return sum;
    }
};