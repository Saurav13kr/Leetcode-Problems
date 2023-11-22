class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> mp;
        
        for(int i=nums.size()-1;i>=0;i--) {
            for(int j=nums[i].size()-1;j>=0;j--) {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        
        vector<int> res;
        for(auto it:mp) {
            vector<int> temp = it.second;
            for(auto j:temp) {
                res.push_back(j);
            }
        }
        return res;
    }
};