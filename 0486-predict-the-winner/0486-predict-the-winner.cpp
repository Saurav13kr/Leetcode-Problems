class Solution {
public:
    int rec(vector<int>& nums , int start , int end , vector<vector<int>>& memo){
        if(memo[start][end]!=NULL){
            return memo[start][end];
        }
        
        if(start==end){
            return nums[start];
        }
        
        int left = nums[start]- rec(nums , start+1 , end , memo);
        int right = nums[end]- rec(nums , start , end-1 , memo);
        return memo[start][end]= max(left , right);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo (n , vector<int> (n));
        return rec(nums , 0 , n-1 , memo)>= 0;
    }
};