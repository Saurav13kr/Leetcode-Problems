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

    bool check(TreeNode* root, vector<int>& v, int& ind)
    {
        if(!root) return true;

        if(!root->left && !root->right)
        {
            if(ind >= v.size() || root->val != v[ind++]) return false;
        }
        
        return check(root->left,v,ind) && check(root->right,v,ind);
    }
    void pre(TreeNode* root, vector<int>& v)
    {
        if(!root) return;
        if(!root->left && !root->right) v.push_back(root->val);
        pre(root->left,v);
        pre(root->right,v); 
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        int ind = 0;
        vector<int> v;
        pre(root1,v);
        return check(root2,v,ind) && ind == v.size();
    }
};