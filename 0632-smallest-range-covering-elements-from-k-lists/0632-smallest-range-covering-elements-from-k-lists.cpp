class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minheap;
        int curmax=INT_MIN;
        for(int i=0;i<nums.size();i++){
            minheap.push({nums[i][0],i,0});
            curmax=max(curmax,nums[i][0]);
        }
        vector<int> smallinterval={0,INT_MAX};
        while(!minheap.empty())
        {
            vector<int>c=minheap.top();
            minheap.pop();
            int curmin=c[0],lindex=c[1],eleindex=c[2];
            if((curmax-curmin<smallinterval[1]-smallinterval[0])||(curmax-curmin==smallinterval[1]-smallinterval[0] && curmin<smallinterval[0])){
                smallinterval[0]=curmin;
                smallinterval[1]=curmax;
            }
            if(eleindex+1<nums[lindex].size())
            {
                int nextval=nums[lindex][eleindex+1];
                minheap.push({nextval,lindex,eleindex+1});
                curmax=max(curmax,nextval);
            } else{
                break;
            }
        }
        return smallinterval;
    }
};