class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        long l = 0, h = INT_MAX, ans = -1;
        while(l <= h) {
            long mid = l + (h - l) / 2;

            if(check(dist, mid, hour))
                ans = mid, h = mid - 1;
            else
                l = mid + 1;
        }

        return ans;
    }

    bool check(vector<int> &dist, int x, double &hour) {
        double cnt = 0;
        for(auto &i : dist) {
            cnt = ceil(cnt);
            cnt += (double) i / x;
        }

        return cnt <= hour;
    }
};