
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root; 
            return newNode;
        }

        queue<pair<TreeNode* ,int>> q;
        q.push({root,1});

        while(!q.empty()){
            auto [node,lvl] = q.front();
            q.pop();

            if(lvl == depth-1){
                TreeNode* ptr = node->left;
                node->left = new TreeNode(val);
                node->left->left = ptr;

                ptr = node->right;
                node->right = new TreeNode(val);
                node->right->right = ptr;
            } else{
                if(node->left) q.push({node->left,lvl+1});
                if(node->right) q.push({node->right,lvl+1});
            }
        }

        return root;
    }
};