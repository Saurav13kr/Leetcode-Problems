class Solution {
public:
    int n;
    std::set<std::vector<int>> st; // To store unique combinations

    void find(int ind, std::vector<int>& candidates, int t, std::unordered_map<int, int>& mp, std::vector<int>& temp) {
        if (t == 0)
        {
            st.insert(temp);
            return;
        }
        if (ind >= n || t < 0) {
            return;
        }
        int currentNum = candidates[ind];
        int maxCount = mp[currentNum];
        
        for (int i = 0; i <= maxCount; ++i) {
            if (t - currentNum * i >= 0) {
                std::vector<int> tempCopy = temp;
                tempCopy.insert(tempCopy.end(), i, currentNum);
                find(ind + maxCount , candidates, t - currentNum * i, mp, tempCopy);
            }
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        n = candidates.size();
        std::sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        std::unordered_map<int, int> mp;
        for (int i : candidates) mp[i]++;
        std::vector<int> temp;
        find(0, candidates, target, mp, temp);
        std::vector<std::vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};