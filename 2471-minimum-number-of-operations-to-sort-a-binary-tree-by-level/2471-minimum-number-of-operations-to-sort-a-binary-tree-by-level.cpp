/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int cycleDecomp(vector<int>& a) {
        int n = a.size(), swaps = 0;
        vector<pair<int, int>> v(n);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; ++i) {
            v[i] = {a[i], i};
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            if (vis[i] || v[i].second == i) {
                continue;
            }
            int sz = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = v[j].second;
                ++sz;
            }
            if (sz > 1) {
                swaps += sz - 1;
            }
        }
        return swaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; ++i) {
                auto t = q.front();
                q.pop();
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
                temp.push_back(t->val);
            }
            res += cycleDecomp(temp);
        }
        return res;
    }
};