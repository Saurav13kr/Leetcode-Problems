class Solution {
public:
    long long maxKelements(const vector<int>& nums, int& k) 
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ret = 0;
        
        while(k--) ret += pq.top(), 
        pq.push((pq.top() + 2) / 3),
        pq.pop();
        return ret;
    }
};