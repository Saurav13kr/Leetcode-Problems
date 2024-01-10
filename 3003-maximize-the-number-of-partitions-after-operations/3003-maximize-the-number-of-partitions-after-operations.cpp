class Solution {
public:
    vector<array<int, 4>> getPrefs(int p, const string &s, int k, char first) {
    vector<array<int, 4>> res;
    int mask = 0, cnt = 0, mid = -1, sz = s.size(), l = 0;
    for (int i = p; i < sz; ++i) {
        int bt = i == p ? first - 'a' : s[i] - 'a';
        if ((mask & (1 << bt)) == 0) {
            if (cnt == k) {
                res.push_back({l, mid, i, mask});
                l = i;
                mid = -1;
                cnt = mask = 0;
            }
            ++cnt;
            mask |= (1 << bt);
            if (cnt == k)
                mid = i;
        }
    }
    res.push_back({l, mid == -1 ? sz : mid, sz, mask});
    return res;  
}
int maxPartitionsAfterOperations(const string &s, int k) {
    if (k == 26)
        return 1;
    auto prefs = getPrefs(0, s, k, s[0]);
    int res = prefs.size(), orig_res = res;
    for (int i = 0; i < prefs.size() && res < orig_res + 2; ++i) {
        auto [l, mid, r, mask] = prefs[i];
        if (r - l > k &&  mid < r) {
            if (res == orig_res && mid - l >= k)
                res = max(res, 1 + i + (int)getPrefs(mid, s, k, s[mid]).size());
            if (res == orig_res || r - mid > k)
                for (char ch = 'a'; ch <= 'z'; ++ch)
                    if ((mask & (1 << (ch - 'a'))) == 0 || ch == s[mid + 1])
                        res = max(res, i + 1 + (int)getPrefs(mid + 1, s, k, ch).size());
        }
    }
    return res;
}
};