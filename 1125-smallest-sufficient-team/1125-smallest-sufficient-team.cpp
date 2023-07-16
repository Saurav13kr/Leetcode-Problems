class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& k,vector<vector<string>>& people){
    const int n = k.size();
    const int z = 1 << n;
    unordered_map<string, int> h;
    unordered_map<int, vector<int>> dp;
    dp.reserve(z); 
    dp[0] = {};

    for (int i = 0; i < n; ++i)
      h[k[i]] = i;
    auto x = [&](const vector<string>& person) {
      int mask = 0;
        
      for (const string& skill : person)
        if (const auto it = h.find(skill); it != h.cend())
          mask |= 1 << it->second;
      return mask;
    };

    for (int i = 0; i < people.size(); ++i) {
      const int l = x(people[i]);
        
      for (const auto& [mask, indices] : dp) {
        const int v = mask | l;
        if (v == mask)  
          continue;
          
        if (!dp.count(v) ||
            dp[v].size() > indices.size() + 1) {
          dp[v] = indices;
          dp[v].push_back(i);
        }
      }
    }

    return dp[z - 1];
  }
};