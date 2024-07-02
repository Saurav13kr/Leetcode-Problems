class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto&ele : nums2)
        {
            mp[ele]++;
        }

        for(auto& ele : nums1){
            if(mp.find(ele) != mp.end() && mp[ele] > 0){
                ans.push_back(ele);
                mp[ele]--;
            }
        }

        return ans;
    }
};