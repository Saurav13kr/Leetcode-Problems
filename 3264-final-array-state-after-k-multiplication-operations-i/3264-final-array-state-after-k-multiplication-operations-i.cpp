class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<nums.size(); ++i)
            pq.push({nums[i],i});
        
        while((k--))
        {
            pair<int,int> cur = pq.top();
            pq.pop();
            pq.push({cur.first*multiplier, cur.second});
        }
        
        while(!pq.empty()){
            pair<int,int> cur = pq.top();
            pq.pop();
            int i = cur.second;
            nums[i] = cur.first;
        }
        return nums;
    }
};