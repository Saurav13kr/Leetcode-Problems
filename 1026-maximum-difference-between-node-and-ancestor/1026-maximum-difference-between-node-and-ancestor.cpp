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
    int ans = -1;
    int mxFunc(TreeNode* root){
        if(!root->left && !root->right) return root->val;
        int mxl = root->left?mxFunc(root->left):-1;
        int mxr = root->right?mxFunc(root->right):-1;

        int omax = max(mxl,mxr);
        ans=max(ans,abs(root->val - omax));
        return max(root->val,omax);
    }
    int mnFunc(TreeNode* root){
        if(!root->left && !root->right) return root->val;
        int mnl = root->left?mnFunc(root->left):100001;
        int mnr = root->right?mnFunc(root->right):100001;

        int omin = min(mnl,mnr);
        ans=max(ans,abs(root->val - omin));
        return min(root->val,omin);
    }
    int maxAncestorDiff(TreeNode* root) {
        mxFunc(root);
        mnFunc(root);
        return ans;
    }
};