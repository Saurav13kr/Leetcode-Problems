class Solution {
public:
    int arraySign(vector<int>& nums) {
        if(count(nums.begin(),nums.end(),0)){
            return 0;
        }
        
        int neg=0;
        sort(nums.begin(),nums.end());
        
        for(auto x:nums){
            if(x<0){
                neg++;
            }
            if(x>=0){
                break;
            }
        }
        
        if(neg%2==1){
            return -1;
            
        } else{
            return 1;
        }
    }
};