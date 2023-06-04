class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        while(nums.size()>0){
            int temp = nums[nums.size()-1];
            nums.pop_back();
            pq.push(temp);
        }
        
        for(int i=0; i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
};