class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        if(p ==  nullptr && q == nullptr){
            return true;
        }
        if(p == nullptr && q != nullptr)return false;
        if(q == nullptr && p != nullptr)return false;
        if(p -> val == q -> val){
            ans &= isSameTree(p->left , q->left);
            ans &= isSameTree(p -> right , q-> right);
        }else{
            ans = false;
        }
        return ans;
    }
};