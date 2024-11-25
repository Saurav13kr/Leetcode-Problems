class Solution {
public:
    unordered_map<int, vector<int>> mp = {{0, {1, 3}},    {1, {0, 2, 4}},
                                          {2, {1, 5}},    {3, {0, 4}},
                                          {4, {1, 3, 5}}, {5, {2, 4}}};

    int slidingPuzzle(vector<vector<int>>& board) {

        string ans;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char ch = board[i][j] + '0';
                ans += ch;
            }
        }
        set<string> st;
        queue<string> q;
        q.push(ans);
        st.insert(ans);

        string res = "123450";

        int lvl = 0;
        while (!q.empty()) {

            int sz = q.size();
            while (sz--) {
                
                auto tt = q.front();
                q.pop();
                if (tt == res)
                    return lvl;

                int zero_ind;
                for (int i = 0; i < tt.size(); i++)
                {
                    if (tt[i] == '0') {
                        zero_ind = i;
                        break;
                    }
                }

                for (auto ind : mp[zero_ind]) {
                    string temp = tt;
                    swap(temp[ind], temp[zero_ind]);
                    if (!st.count(temp)) 
                    {
                        q.push(temp);
                        st.insert(temp);
                    }
                }
            }
            lvl++;
        }
        cout << ans << endl;
        return -1;
    }
};