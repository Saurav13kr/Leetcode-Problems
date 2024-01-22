class Solution {
public: 
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long double Pdp = 1, s = 0, dividend = n;
        for(auto&num:nums){
            Pdp *= dividend--/num;     
            s += num;
        }
        long double S = n*(n+1)/2, x = (S - s)/(Pdp - 1), y = S - s + x;
        return {static_cast<int>(round(x)),static_cast<int>(round(y))};
    }
};