class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        unordered_map<long long, int> map;
        for(int i : nums){
            map[i]++;
        }
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int len = 1;
            long long a = nums[i];
            while(map.find(a*a)!=map.end())
            {
                len++;
                a = a*a;
            }
            ans = max(len, ans);
        }
        if(ans==1){
            return -1;
        }
        return ans;
        
    }
};