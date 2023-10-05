class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(auto it: nums){
            m[it]++;
        }
        int n= floor( nums.size()/3 );
        
        for(auto it :m){
            if(it.second>n)
                ans.push_back(it.first);
        }
        return ans;
    }
};