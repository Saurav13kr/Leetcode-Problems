class Solution {
public:
    int maxDistance(vector<vector<int>>& nums) {
        int mainMin = nums[0][0];
        int mainMax = nums[0].back();
        int res = -1e4;

        for (int i = 1; i < nums.size(); i++) 
        {
            int currentMin = nums[i][0];
            int currentMax = nums[i].back();

            res = max(res, abs(mainMax - currentMin));
            res = max(res, abs(currentMax - mainMin));
            mainMin = min(mainMin, currentMin);
            mainMax = max(mainMax, currentMax);
        }
        return res;
    }
};