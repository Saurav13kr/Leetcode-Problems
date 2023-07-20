class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) {
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        int l,h;
        int cn=0;
        
        for(int i=nums.size()-1;i>=2;i--) {
            l=0;
            h=i-1;
            
            while(l<h) {
                if(nums[l]+nums[h]>nums[i]) {
                    cn+=(h-l);
                    h--;
                } else {
                    l++;
                }
            }
        }
        return cn;
    }
};