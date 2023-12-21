class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> ans;
        int n = points.size();

        for(int i= 0; i<n; i++){
            ans.push_back(points[i][0]);
        }
        
        sort(ans.begin(),ans.end());            
        int result = INT_MIN;
        
        for(int i = 1; i<ans.size(); i++){
            int com = ans[i]-ans[i-1];            
            result = max(com,result);
        }
        return result;
    }
};