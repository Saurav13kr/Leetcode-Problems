class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int mn=1e6, cnt=0;
        
        for (auto it:matrix) 
            for (auto i:it)
                cnt+=i<1,
                mn=min(mn, abs(i)), 
                sum+=abs(i);
        return cnt%2? sum-2*abs(mn):sum;
    }
};