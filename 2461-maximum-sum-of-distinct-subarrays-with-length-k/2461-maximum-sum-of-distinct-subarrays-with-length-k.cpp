class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long answer = 0; 
        unordered_map<int, int> frequency_map; 
        long long current_sum = 0; 
        int left_pointer = 0;
        int n = nums.size(); 

        for (int i = 0; i < n; i++)
        {
            frequency_map[nums[i]]++; 
            current_sum += nums[i];  
            
            if (i - left_pointer + 1 == k) { 
                if (frequency_map.size() == k) { 
                    answer = max(answer, current_sum);
                }
                frequency_map[nums[left_pointer]]--;
                if (frequency_map[nums[left_pointer]] == 0) {
                    frequency_map.erase(nums[left_pointer]);
                }
                current_sum -= nums[left_pointer];
                left_pointer++;
            }
        }
        return answer;
    }
};