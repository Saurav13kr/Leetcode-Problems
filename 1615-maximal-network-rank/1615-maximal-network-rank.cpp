class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        std::vector<int> degrees(n, 0);
        std::unordered_map<int, std::unordered_set<int>> directlyConnected;
        for (const auto& road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
            directlyConnected[road[0]].insert(road[1]);
            directlyConnected[road[1]].insert(road[0]);
        }
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (directlyConnected[i].count(j)) {
                    result = std::max(result, degrees[i] + degrees[j] - 1);
                } else {
                    result = std::max(result, degrees[i] + degrees[j]);
                }
            }
        }
        return result;
    }
};