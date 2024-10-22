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
    void getSum(TreeNode * root, vector<long long>& vec, int h) {
        if(!root)
        return;

        if(h+1>vec.size())
        vec.push_back(root->val);
        else
        vec[h] += root->val;

        getSum(root->left, vec, h+1);
        getSum(root->right, vec, h+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        vector<long long> vecH;
        getSum(root, vecH, 0);
        sort(vecH.begin(), vecH.end(), greater<long long>());
        return k<=vecH.size() ? vecH[k-1] : -1;
    }
};