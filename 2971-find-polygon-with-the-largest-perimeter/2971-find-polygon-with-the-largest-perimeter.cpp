class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        long long sum=0;
        
        for(int i=0; i<nums.size(); i++){
         sum +=  static_cast<long long> (nums[i]);
        }
        for(int i=nums.size()-1; i>=2; i--){
            if(sum-nums[i]>nums[i]) return sum;
            else sum = sum - nums[i];
        }
        return -1;
    }
};