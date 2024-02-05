class Solution {
public:
  vector<int> getLps(const string& s) {
    int n = s.size();
    int len = 0;
    vector<int> lps(n, 0);
    for (int i = 1; i < n; ++i) {
      if (s[i] == s[len]) {
        lps[i] = ++len;
      } else {
        len = 0;
      }
    }
    return lps;
  }
  
  vector<int> getAllIdcs(const string& s, const string& patt) {
    int sIdx = 0, pattIdx = 0;
    int sLen = s.size(), pattLen = patt.size();
    auto lps = getLps(patt);
    vector<int> idcs;
    while (sIdx < sLen) {
      if ((sLen - sIdx) < (pattLen - pattIdx)) break;
      if (s[sIdx] == patt[pattIdx]) {
        ++pattIdx;
        if (pattIdx == pattLen) {
          idcs.push_back(sIdx + 1 - pattLen);
          if (pattIdx != 0) pattIdx = lps[pattIdx - 1];
          else pattIdx = 0;
        }
        sIdx++;
      } else {
        if (pattIdx != 0) pattIdx = lps[pattIdx - 1];
        else sIdx++;
      }
    }
    return idcs;
  }
  
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    auto aIdcs = getAllIdcs(s, a);
    auto bIdcs = getAllIdcs(s, b);
    vector<int> result;
    int aPtr = 0, bPtr = 0;
    while (aPtr < aIdcs.size()) {
      while (bPtr < bIdcs.size() && (aIdcs[aPtr] - bIdcs[bPtr]) > k) {
        bPtr++;
      }
      if (bPtr >= bIdcs.size()) break;
      if (abs(aIdcs[aPtr] - bIdcs[bPtr]) <= k) {
        result.push_back(aIdcs[aPtr]);
      }
      aPtr++;
    }
    return result;
  }
};