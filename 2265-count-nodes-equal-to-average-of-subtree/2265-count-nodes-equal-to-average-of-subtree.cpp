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
    int numberOfNodes(TreeNode* root,int &nodeCount,int &ans) {
        if(root==NULL)
            return 0;
        
        int temp,leftSubtreeSum,rightSubtreeSum,avgValue;
        leftSubtreeSum=numberOfNodes(root->left,nodeCount,ans);
        
        temp=nodeCount;
        nodeCount=0;
        rightSubtreeSum=numberOfNodes(root->right,nodeCount,ans);
        nodeCount=temp+nodeCount+1;

        avgValue=(leftSubtreeSum+rightSubtreeSum+root->val)/nodeCount;
        if(root->val==avgValue)
            ans++;        
        return leftSubtreeSum+rightSubtreeSum+root->val;
    }

    int averageOfSubtree(TreeNode* root) {
        int nodeCount=0, ans=0,sum;
        sum = numberOfNodes(root,nodeCount,ans);
        return ans;
    }
};