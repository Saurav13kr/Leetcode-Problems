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
    int helper(TreeNode* root, int startValue, int destValue, string& path1, string& path2)
    {
        if (!root) return 0;

        int l=helper(root->left, startValue, destValue, path1, path2);
        int r=helper(root->right, startValue, destValue, path1, path2);

        if (l==-1||r==-1) return -1;

        if (root->val==startValue||root->val==destValue) {
            if (l){
                
                if (l==startValue) path1.push_back('U');
                else path2.push_back('L');

                return -1;
            }
            else if (r){

                if (r==startValue) path1.push_back('U');
                else path2.push_back('R');

                return -1;
            }
            return root->val;
        }
        
        if (l&&r){

            path1.push_back('U');

            if (l==destValue) path2.push_back('L');
            else path2.push_back('R');

            return -1;
        } 
        else if (l){

            if (l==startValue) path1.push_back('U');
            else path2.push_back('L');

            return l;
        } 
        else if (r){

            if (r==startValue) path1.push_back('U');
            else path2.push_back('R');

            return r;
        }

        return 0;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        string path1="";
        string path2="";
        helper(root, startValue, destValue, path1, path2);
        reverse(path2.begin(), path2.end());
        path1=path1+path2;
        return path1;
    }
};