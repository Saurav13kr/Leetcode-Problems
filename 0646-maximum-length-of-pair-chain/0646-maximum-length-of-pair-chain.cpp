class Solution {
public:
    static bool cmp(pair<int,int> p1,pair<int,int>p2) {
        return p1.second < p2.second;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>> toStorePair;

        for(int i=0;i<pairs.size();i++){
            pair<int,int> p = make_pair(pairs[i][0],pairs[i][1]);
            toStorePair.push_back(p);
        }
        
        sort(toStorePair.begin(),toStorePair.end(),cmp);
        int ans = 1;
        int ansMax = toStorePair[0].second;
        
        for(int i=0;i<toStorePair.size();i++){
            if(ansMax < toStorePair[i].first) {
                ans++;
                ansMax = toStorePair[i].second;
            }
            cout<< toStorePair[i].first <<" "<< toStorePair[i].second<<" ";
        }
        return ans;
    }
};