class Solution {
public:
    int findMin(vector<int>& c) {
        int r = c.size()-1, l = 0, mid;
        if (!r) return c[0]; 

        while (l < r) {
            mid = l + (r - l) / 2;
            if (c[l] < c[r]) return c[l]; 
            else if (c[mid] > c[r]) l = mid + 1;
            else r = mid;
        }
        return c[l];
    }
};