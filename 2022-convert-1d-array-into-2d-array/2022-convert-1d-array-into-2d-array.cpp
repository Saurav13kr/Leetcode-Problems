class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        int cnt = 0;
        for(int i=0;i<original.size();i++){
            temp.push_back(original[i]);
            cnt++;
            if(cnt == n){
                ans.push_back(temp);
                temp.clear();
                cnt = 0;
            }
        }
        if(temp.size()>0)
        {
            ans.push_back(temp);
        }

        if(ans[0].size()!=n || ans.size()!=m) return {};
        return ans;
    }
};