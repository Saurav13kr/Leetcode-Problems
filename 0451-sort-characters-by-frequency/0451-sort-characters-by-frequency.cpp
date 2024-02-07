class Solution {
public:
    static bool cmp(const pair<int, char>& a, const pair<int, char>& b){
        return a.first > b.first;
    }
    string frequencySort(string s) {
        int n = s.size();
        vector<pair<int, char>> vec(123);
        for(int i=0; i<n; i++){
            vec[s[i]].first++; vec[s[i]].second = s[i];
        }
        sort(vec.begin(), vec.end(), cmp);
        string ans = "";
        for(int i=0; i<123; i++){
            ans += string(vec[i].first, vec[i].second);
        }
        return ans;
    }
};