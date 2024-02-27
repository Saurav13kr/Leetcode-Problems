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
    int d(TreeNode* root, int &res) {
        if(root==nullptr) {
            return 0;
        }

        int left=d(root->left,res);
        int right=d(root->right,res);

        int temp=max(left,right)+1;
        int ans=max(temp,left+right+1);
        res=max(ans,res);
        return temp;

    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        d(root,res);
        return res-1;
    }
};