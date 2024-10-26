class Solution {
public:
    int maxHeight[100001];
    int currMax=0;
    void leftTraverse(TreeNode *root,int curr)
    {
        if(root==NULL) return;
        maxHeight[root->val]=currMax;
        currMax=max(currMax,curr);
        leftTraverse(root->left,curr+1);
        leftTraverse(root->right,curr+1);
    }
    void rightTraverse(TreeNode *root,int curr)
    {
        if(root==NULL) return;
        maxHeight[root->val]=max(maxHeight[root->val],currMax);
        currMax=max(currMax,curr);
        rightTraverse(root->right,curr+1);
        rightTraverse(root->left,curr+1);
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        leftTraverse(root,0);
        currMax=0;
        rightTraverse(root,0);
        vector<int> ans;
        
        for(auto it:queries)
        {
            ans.push_back(maxHeight[it]);
        }
        return ans;
    }
};