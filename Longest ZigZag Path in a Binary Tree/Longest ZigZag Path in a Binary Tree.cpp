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
    int ans = 0;
    map <pair < TreeNode*,bool>, int > mp;

    int longestZigZag(TreeNode* root) {
      preorder(root);
        return ans;
        
    }

    void preorder(TreeNode*root) {
        if(root!=NULL) {
            if(root -> left != NULL) {
                ans=max(ans,findzig(root->left,true));   
            }

            if(root->right!=NULL) {
                ans=max(ans,findzig(root->right,false));
            }

            preorder(root->left);  
            preorder(root->right);
        }
    }

    int findzig(TreeNode*root, bool chk) {
        if(mp.find({root, chk}) != mp.end()) return mp[{root,chk}];   
        if(chk){
            
            if(root -> right!=NULL) {
                return mp[{root,chk}]=1+findzig(root->right,!chk); 
            }
            }
            else {
                if(root -> left != NULL) {
                    return mp[{root,chk}]=1+findzig(root->left,!chk); 
                }
            }
        return mp[{root,chk}]=1;
    }
};
