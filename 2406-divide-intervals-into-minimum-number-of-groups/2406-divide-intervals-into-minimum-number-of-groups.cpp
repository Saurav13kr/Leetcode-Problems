class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>>vec;
        int n = intervals.size();
        for(int i = 0 ;i < n ; i++){
            vec.push_back({intervals[i][0], 1}); //enter
            vec.push_back({intervals[i][1], 2}); //leave
        }
        sort(vec.begin() , vec.end());
        int ans = 0, count = 0;
        
        for(int i = 0;i < vec.size() ; i++)
        {
            if(vec[i].second == 1){
                count++;
            }else{
                count--;
            }
            ans = max(ans , count);
        }
        return ans;
    }
};