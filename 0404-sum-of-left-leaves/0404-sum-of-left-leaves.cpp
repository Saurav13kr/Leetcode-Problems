
class Solution {
public:
    void getSum(TreeNode* root,int &sum, bool isLeft)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            sum += (isLeft? root->val : 0);
            return;
        }
        getSum(root->left,sum,true);
        getSum(root->right,sum,false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum = 0;
        getSum(root->left,sum,true);
        getSum(root->right,sum,false);
        return sum;
    }
};