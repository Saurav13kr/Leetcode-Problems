class Solution {
public:
    int missingNumber(vector<int>& nums) { // find the missing number in a array
        int sum = 0; // sum of all numbers initially 0
        int total = nums.size()*(nums.size() + 1)/2;
        for (auto number : nums) { // iterate through the array
            sum += number; // add the number to the sum
        }
        return total - sum; 
    }
};