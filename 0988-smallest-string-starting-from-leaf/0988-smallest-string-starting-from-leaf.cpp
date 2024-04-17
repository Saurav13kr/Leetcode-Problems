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
private:
    set<string> st;
    void dfs(TreeNode* root, string temp){
        if (!root) return;
        if (!root->left && !root->right) {
            temp = char('a' + root->val) + temp;
            st.insert(temp);
            if(st.size() > 1){
                auto it = st.end();
               --it;
                st.erase(it);
            }
            
            return;
        }
        
        temp = char('a' + root->val) + temp;
        dfs(root->left, temp);
        dfs(root->right, temp);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        string temp = "";
        dfs(root, temp);
        return *st.begin();
    }
};