class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) 
    {
        sort(items.begin(), items.end());

        for (int i = 1; i < items.size(); ++i) 
        {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        vector<int> result;
        for (int q : queries) 
        {
            auto it = lower_bound(
                items.rbegin(), items.rend(), q,
                [](const vector<int>& item, int target) { return item[0] > target; });
            result.push_back(it != items.rend() ? (*it)[1] : 0);
        }

        return result;
    }
};