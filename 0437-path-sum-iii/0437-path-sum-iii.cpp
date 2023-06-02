class Solution {
public:
    int count =0;
    void Helper(TreeNode* root, long curr, int target) {
        if(root==NULL)
            return;
        
        curr += root->val;
        if(curr==target)
            count++;
        
        Helper(root->left,curr,target);
        Helper(root->right,curr,target);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        
        Helper(root,0,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
        
    }
};