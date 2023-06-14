class Solution {
    private :
    void Inorder(TreeNode* root ,vector<int>& inorder)
    {
        if(root == NULL){
            return ;
        }
        Inorder(root->left , inorder);
        inorder.push_back(root->val);
        Inorder(root->right , inorder);
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        Inorder(root,inorder);
        int min_diff = INT_MAX;
        
        for(int i = 1 ; i<inorder.size();i++)
        {
            min_diff = min(min_diff , inorder[i]-inorder[i-1]);
        }
        
        return min_diff;
    }
};