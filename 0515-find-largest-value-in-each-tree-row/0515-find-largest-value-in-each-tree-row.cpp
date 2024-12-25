class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            int maxValue = INT_MIN;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* top = q.front();
                q.pop();
                maxValue = max(maxValue, top->val);
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            result.push_back(maxValue);
        }
        return result;
    }
};