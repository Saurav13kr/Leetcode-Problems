class Solution {
public:
    void solve(vector<int> & candi, vector<vector<int>>& ans, vector<int> temp, int ind, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        if(ind == candi.size() ){
            return;
        }

        if(candi[ind] <= target){ 
            temp.push_back(candi[ind]);
            solve(candi, ans, temp, ind+1, target - candi[ind]);
            temp.pop_back();
        }

        while(ind + 1 < candi.size() && candi[ind + 1] == candi[ind]) ind++;  

        solve(candi, ans, temp, ind + 1, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        vector<vector<int>> ans;
        
        vector<int> temp;
        sort(candi.begin(), candi.end());
        solve(candi, ans, temp, 0, target);
        
        return ans;     
    }
};