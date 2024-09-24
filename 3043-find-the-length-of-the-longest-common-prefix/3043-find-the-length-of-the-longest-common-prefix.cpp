class Solution {
public:
    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        int max_ = 0;
        unordered_set<int> set_1, set_2;
        for (auto i : a) {
            while (i) {
                set_1.insert(i);
                i /= 10;
            }
        }
        for (auto i : b) 
        {
            while (i) {
                set_2.insert(i);
                i /= 10;
            }
        }
        for (auto i : set_1) 
        {
            if (set_2.count(i)) 
            {
                int x = to_string(i).size();
                max_ = max(max_, x);
            }
        }
        return max_;
    }
};