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
    int findBottomLeftValue(TreeNode* root) {
        int leftMost = root->val;
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while (q.size() > 1) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr) {
                if (!q.empty())
                    leftMost = q.front()->val;
                q.push(nullptr);
                continue;
            }

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return leftMost;
    }
};