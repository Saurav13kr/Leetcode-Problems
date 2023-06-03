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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)  return 0;
        int maxi=INT_MIN;
        int lev=1,res=0;
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size()){
            int sum=0,n=q.size();
            for(int i=0;i<n;i++){
                auto t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right)   q.push(t->right);
                sum+=t->val;
            }
            if(sum>maxi){
                maxi=sum;
                res=lev;
            }
            lev++;
        }
        return res;
    }
};