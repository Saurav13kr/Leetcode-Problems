class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0 ;
        }
        
        sort(nums.begin() , nums.end()) ;
        int ans = 0 ;
        
        for(int i = 1 ; i < nums.size() ; i ++ ){
            int res = 0 ;
            if((nums[i] - nums[i-1] ) > res ){
                res = nums[i] - nums[i-1] ;
            }
           if(res > ans)
           ans = res ;
        }
        return ans ;
        
    }
};