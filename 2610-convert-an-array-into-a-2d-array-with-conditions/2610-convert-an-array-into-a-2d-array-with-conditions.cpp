class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxrep=0;   
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxrep = max(mp[nums[i]],maxrep);
        }
        
        vector<vector<int>> ans;
        while(maxrep){   
            vector<int> temp;
            for(auto &i:mp){
                if(i.second >= 1){
                    temp.push_back(i.first); 
                    i.second = i.second-1;  
                }
            }
            
            ans.push_back(temp);
            maxrep--;
        }
        
        return ans;
    }
};