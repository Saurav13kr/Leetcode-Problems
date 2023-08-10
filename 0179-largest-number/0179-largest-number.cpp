class Solution {
    private:
    static bool compare(string s1, string s2) {
        return s1 + s2 > s2 + s1;
    }
    
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> s(n);
        for(int i = 0; i < n; i++)
            s[i] = to_string(nums[i]); 
        sort(s.begin(), s.end(), compare);
        int i = 0;
        while(i < n-1 && s[i] == "0") i++;

        string ans = "";
        for(; i < n; i++) ans += s[i];
        return ans;
    }
};