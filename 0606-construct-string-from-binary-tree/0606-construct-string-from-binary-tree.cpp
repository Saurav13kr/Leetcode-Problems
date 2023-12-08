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
    void solve(TreeNode* root, string &curr) {
        
        if(!root) return;

        curr += to_string(root -> val);
        
        if(root -> left or root -> right) {
            curr += "(";
            solve(root -> left, curr);
            curr += ')';
        }

        if(root -> right) {
            curr += '(';
            solve(root -> right, curr);
            curr += ')';
        }
    }

    string tree2str(TreeNode* root) {
        string res = "";
        solve(root, res);
        return res;
    }
};