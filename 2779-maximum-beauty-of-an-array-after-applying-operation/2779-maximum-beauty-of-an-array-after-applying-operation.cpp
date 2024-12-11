class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int start = nums[i] - k;
            int end = nums[i] + k;
            mp[start]++;
            mp[end + 1]--;
        }
        
        int ans = 0;
        int count =0;
        for(auto i : mp)
        {
            count += i.second;
            if(count>1){
                ans = max(ans,count);
            }
        }
        return ans==0 ? 1 : ans;
    }
};