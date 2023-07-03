class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        if(goal.size() != n) return false;

       if(s == goal) {
           unordered_set<char> seen;
           for(char c : s) {
               if(seen.find(c) != seen.end()) return true;
               seen.insert(c);
           }
           return false;
       }

       vector<int> idx;
       for(int i=0; i<n; i++) {
           if(s[i] != goal[i]) idx.push_back(i);
       }

       if(idx.size() == 2) {
           if(s[idx[0]] == goal[idx[1]] && s[idx[1]] == goal[idx[0]]) return true;
       }
       return false;
    }
};