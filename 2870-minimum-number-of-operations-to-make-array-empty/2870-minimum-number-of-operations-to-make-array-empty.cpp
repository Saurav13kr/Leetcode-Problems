class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> mp;
        for(int i : nums) mp[i]++;
        int res = 0;
        for(auto it : mp) {
            if(it.second >= 5) { // as if freq reaches 5, it's always possible (3+2 = 5)
                while(it.second >= 5) {
                    it.second -= 3;
                    res++;
                }
            }
                if(it.second == 4) res += 2;
                if(it.second == 3) res++;
                if(it.second == 2) res++;
                if(it.second == 1) return -1; // single element, no operation available
        }
        return res;
    }
};