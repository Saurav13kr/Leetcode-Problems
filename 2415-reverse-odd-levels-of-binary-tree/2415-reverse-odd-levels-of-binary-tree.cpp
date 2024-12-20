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
public:
   TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        int sz = q.size();
        vector<int> v;
        for(int i=0; i<sz; ++i){
            ++lvl;
            while(sz--)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left && cur->right){
                    if(lvl&1){
                        v.push_back(cur->left->val);
                        v.push_back(cur->right->val);
                    }
                    q.push(cur->left);
                    q.push(cur->right);
                }
                if(lvl%2==0 && lvl != 0){
                    cur->val = v.back();
                    v.pop_back();
                }
            }
            if(lvl%2==0) v.clear();
            sz = q.size();
        }
        return root;
    }
};