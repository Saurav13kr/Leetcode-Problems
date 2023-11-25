class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>ans;
        int x = nums.size();
        int sum = 0;
          for(auto i : nums){
              sum+=i;          
          }
        
        int left = 0, right=sum;
        
        for(int i  = 0;i<nums.size();i++){
               right = right-nums[i];
               int ind = x-i-1;
               int a = ind*nums[i];
               int indf = (i)*nums[i];
              
              int b = abs(left-indf);
              
              ans.push_back(right-a + b);
              left+=nums[i];
        }
        return ans;
    }
};