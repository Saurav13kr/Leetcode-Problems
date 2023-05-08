class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, curr = 0;
        
        for (int n: gain) {
            curr += n;
            res = max(res, curr);
        }
        
        return res;
    }
};