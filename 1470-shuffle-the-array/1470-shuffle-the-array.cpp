class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int>c;
        for(int i=0,j=n;i<n,j<2*n;i++,j++){
            c.push_back(nums[i]);
            c.push_back(nums[j]);
        }
        
        return  c;
        
    }
};