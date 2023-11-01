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
    int currentcount, currentelement;
    int mode;
    vector<int> freqCounter;
public:
    vector<int> findMode(TreeNode* root) {
        mode = 0;
        currentcount = 0;
        currentelement = INT_MIN;
        inorder(root);
        
        if (currentcount > mode) {
            freqCounter.clear();
            freqCounter.push_back(currentelement);
        } 
        
        else if (currentcount == mode) {
            freqCounter.push_back(currentelement);
        }
        return freqCounter;
    }
    
    void inorder(TreeNode *root) {
        if (root == nullptr) return;
        
        inorder(root->left);
        if (root->val == currentelement) {
            currentcount++;
            
        } 
        else {
            if (currentcount > mode) {
                freqCounter.clear();
                freqCounter.push_back(currentelement);
                
            } 
            else if (currentcount == mode) {
                freqCounter.push_back(currentelement);
            }
            mode = max(mode, currentcount);
            currentelement = root->val;
            currentcount = 1;
        }
        
        inorder(root->right);
    }
};