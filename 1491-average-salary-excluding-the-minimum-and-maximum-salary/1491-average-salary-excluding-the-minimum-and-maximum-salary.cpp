class Solution {
public:
    double average(vector<int>& s) {
        
        sort(s.begin(),s.end());
        s.erase(s.begin());
        s.erase(s.begin()+(s.size()-1));
        
        double ans=0.00000;
        ans=(double)((double)accumulate(s.begin(), s.end(), 0))/(double)(s.size());
        
        return ans;
    }
};