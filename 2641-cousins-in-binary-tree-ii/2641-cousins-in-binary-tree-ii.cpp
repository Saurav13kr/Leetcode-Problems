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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;  // Edge case, empty tree
        
        // BFS queue
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;  // Root node has no cousins, so set its value to 0.
        
        while (!q.empty()) {
            int sz = q.size();
            int levelSum = 0;
            vector<TreeNode*> nodes;  // To store the current level's nodes
            
            // Calculate total sum of current level
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node);
                
                if (node->left) {
                    levelSum += node->left->val;
                    q.push(node->left);
                }
                if (node->right) {
                    levelSum += node->right->val;
                    q.push(node->right);
                }
            }
            
            for (TreeNode* node : nodes) {
                int siblingSum = 0;
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;
       
                if (node->left) node->left->val = levelSum - siblingSum;
                if (node->right) node->right->val = levelSum - siblingSum;
            }
        }
        
        return root;
    }
};
