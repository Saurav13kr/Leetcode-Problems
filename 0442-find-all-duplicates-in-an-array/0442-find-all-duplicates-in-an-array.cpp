class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> freq(nums.size()+1, 0);
        vector<int> result;
        for(int num: nums) {
            if(freq[num]) result.push_back(num);
            freq[num]++;
        }

        return result;
    }
};