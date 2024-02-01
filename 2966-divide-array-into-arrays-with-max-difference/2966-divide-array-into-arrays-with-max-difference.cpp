class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>resilt; 
        sort(nums.begin(),nums.end());
         
        if(nums.size()%3!=0){
            return resilt;
        }
        for(int i=0;i<=nums.size()-3;i+=3){
            
            if(nums[i+2]-nums[i]<=k){
                resilt.push_back({nums[i],nums[i+1],nums[i+2]});
            }else{
                return {};
            } 
        }
        return resilt;

    }
};