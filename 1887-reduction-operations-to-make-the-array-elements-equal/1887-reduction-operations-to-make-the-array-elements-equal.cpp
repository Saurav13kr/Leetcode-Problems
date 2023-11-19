class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            if(pq.empty()){
                pq.push(nums[i]);
            }
            else{
                if(pq.top()!=nums[i]){
                    pq.push(nums[i]);
                }
            }
            mp[nums[i]]++;
        }
        int count=0;
        
        while(pq.size()>1){
            int num=pq.top();
            pq.pop();
            int numF=mp[num];
            int nextMin=pq.top();
            count+=numF;
            mp[nextMin]+=numF;
        }
        return count;
    }
};