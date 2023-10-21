class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        int ans=nums[0];
        
        for(int i=1;i<nums.size();i++){
            while(i-pq.top().second>k){
                pq.pop();
            }
            
            int j=pq.top().first+nums[i];
            int d=max(j,nums[i]);
            
            pq.push({d,i});
            ans=max(ans,d);
        }
        
        return ans;
    }
};