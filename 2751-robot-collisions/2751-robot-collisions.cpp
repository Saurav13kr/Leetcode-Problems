class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> index(n);
        for (int i = 0; i < n; ++i) {
            index[i] = i;
        }
        sort(index.begin(), index.end(), [&](int i, int j){
            return positions[i] < positions[j];
        });
        stack<int> s;
        for (auto i : index) {
            if (directions[i] == 'R') {
                s.push(i);
                continue;
            }
            while (!s.empty() and healths[i] > 0) {
                int j = s.top();
                s.pop();
                if (healths[i] > healths[j]) {
                    healths[i]--;
                    healths[j] = 0;
                } 
                else if (healths[i] < healths[j]) {
                    healths[i] = 0;
                    healths[j]--;
                    s.push(j);
                } 
                else {
                    healths[i] = 0;
                    healths[j] = 0;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};