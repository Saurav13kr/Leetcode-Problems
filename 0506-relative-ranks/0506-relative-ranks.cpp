class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> indices(score.size());
        for(int i = 0; i < score.size(); i++){
            indices[i] = {score[i],i};
        }
        vector<string> ans(score.size());
        sort(indices.begin(), indices.end(), greater<pair<int, int>>());
        
        for(int i = 0; i < indices.size(); i++){
            int realpos = indices[i].second;
            if(i == 0) ans[realpos] = "Gold Medal";
            else if(i == 1) ans[realpos] = "Silver Medal";
            else if(i == 2) ans[realpos] = "Bronze Medal";
            else ans[realpos] = to_string(i + 1);
        }

        return ans;
    }
};