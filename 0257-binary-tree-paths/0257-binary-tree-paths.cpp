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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s = to_string(root->val);
        gen(root, s, v);
        return v;
    }
    void gen(TreeNode* root, string curr, vector<string>& ret){
        if(root->left == nullptr && root->right == nullptr){
            ret.push_back(curr);
            return;
        }
        if(root->left != nullptr){
            curr = curr + "->" + to_string(root->left->val);
            gen(root->left, curr, ret);
            truncate(curr);
        }
        if(root->right != nullptr){
            curr = curr + "->" + to_string(root->right->val);
            gen(root->right, curr, ret);
            truncate(curr);
        }
    }
    void truncate(string& s){
        auto it = s.find_last_of('>');
        s.erase(s.begin() + it - 1, s.end());
    }
};