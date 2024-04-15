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
    int solve(TreeNode* root,int &ans){
        if(root==NULL)
           return 0;
        
        if(root->left==NULL && root->right==NULL)
        {
           return ans*10+root->val;
        }
        
        int sum=0;
        ans=ans*10+root->val;
        int curr=ans;
        int left = solve(root->left,ans);
        ans=curr;
        int right = solve(root->right,ans);
        sum=left+right;
        return sum;
    }
    int sumNumbers(TreeNode* root) {
        int cnt=0;
        int ans=solve(root,cnt);
        return ans;     
    }
};