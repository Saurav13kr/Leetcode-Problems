class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r && s[l] == s[r]) {
            while (l + 1 != r && s[l + 1] == s[r]) {
                l += 1;
            }
            while (r - 1 != l && s[r - 1] == s[l]) {
                r -= 1;
            }
            l += 1;
            r -= 1;
        }
        return r - l + 1;
    }
};