class Solution {
public:
    int minimumDepth = INT_MAX;
    void dfs(TreeNode* node, int depth) {
        if (!node)
            return;

        if (!node->left && !node->right)
            minimumDepth = min(depth, minimumDepth);

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
 
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        dfs(root, 1);

        return minimumDepth;
    }
};