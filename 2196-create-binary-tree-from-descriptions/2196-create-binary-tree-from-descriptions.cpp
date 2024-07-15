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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<TreeNode*,int> mp1;
        for(auto description:descriptions){
            TreeNode* root;
            if(mp.find(description[0])==mp.end()){
                root=new TreeNode(description[0]);
            }
            else{
                root=mp[description[0]];
            }
            
            TreeNode* child;
            if(mp.find(description[1])==mp.end()){
                child=new TreeNode(description[1]);
            }
            else{
                child=mp[description[1]];
            }
            if(description[2]==1){
                root->left=child;
            } else{
                root->right=child;
            }
            mp[description[0]]=root;
            mp[description[1]]=child;
            mp1[child]=root->val;
            if(mp1.find(root)==mp1.end()){
                mp1[root]=-1;
            }
        }
        TreeNode* ans;
        for(auto p:mp1){
            if(p.second==-1){
                ans=p.first;
                break;
            }
        }
        return ans;
    }
};