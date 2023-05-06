class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k);
};

double Solution::findMaxAverage(vector<int>& nums, int k) {
    int sum = 0, i, size = nums.size();
    double maxKAverage = INT_MIN, avg;
    
    for (i = 0; i < size; ++i) {
        if (i < k) {
            sum += nums[i];
        } 
        
        else {
            sum += nums[i] - nums[i-k];
        }
        
        if (i >= k - 1) {
            avg = static_cast<double>(sum)/k;
            if (maxKAverage < avg) {
                maxKAverage = avg;
            }
        }
    }
    
    return maxKAverage;
}