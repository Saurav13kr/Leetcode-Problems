class Solution {
public:
    int f(vector<int>& nums,int start,int end){
        for(int i=start;i<end;i++){
            if(nums[i]+1!=nums[i+1]) return -1;
        }
        return nums[end];
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        int i=0;
        int j=0;
        while(j<n)
        {
            if(j-i+1<k)
            {
                j++;
            }
            else{
                 ans.push_back(f(nums,i,j));
                 i++;
                 j++;
            }
        }
        return ans;
        
    }
};