class Solution {
public:
    bool ispossible(int mid,vector<int>& nums,int p){
        
        int ans=0;
        int lastind=-1;
        for(int i=0;i<nums.size()-1;i++) {
            if(lastind==i) continue;
            if(abs(nums[i]-nums[i+1])<=mid)
            {
             ans++;
             lastind=i+1;
            }
        }
        return ans>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {    
        sort(nums.begin(),nums.end());
        int l=0,h=nums[nums.size()-1]-nums[0],ans;
        
        while(l<=h){
            int m=(l+h)/2;
        
            if(ispossible(m,nums,p)){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;       
    }
};