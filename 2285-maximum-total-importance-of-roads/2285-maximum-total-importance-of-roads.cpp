class Solution {
public:
    static bool cmp(pair<int, int> pair1, pair<int, int> pair2) {
        return pair1.second > pair2.second;
    }

    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < roads.size(); i++) {
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        vector<pair<int, int>> counts;
        for (auto it : mp) {
            counts.push_back({it.first, it.second});
        }

        sort(counts.begin(), counts.end(), cmp);

        int num = n;
        long long ans = 0;
        for (int i = 0; i < counts.size(); i++) {
            ans += (long long)num * counts[i].second;
            num--;
        }
        return ans;
    }
};