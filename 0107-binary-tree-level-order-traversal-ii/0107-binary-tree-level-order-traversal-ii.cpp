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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL){return {};}
        vector<vector<int>>ans;
        queue<TreeNode*>pq;
        pq.push(root);
        while(pq.size()>0){
            int size =pq.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                TreeNode* value= pq.front();
                pq.pop();
                if(value!=NULL){
                temp.push_back(value->val);
                }
                if(value!=NULL && value->left){
                    pq.push(value->left);
                }
                 if(value!=NULL && value->right){
                    pq.push(value->right);
                }
                
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};