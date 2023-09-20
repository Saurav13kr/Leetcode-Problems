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
    TreeNode* recoverFromPreorder(string trav) {
        stack<TreeNode*> s;
        int i = 0;
        
        while(i < trav.size()){
            int lev = 0, j = i;
            while(j < trav.size() && trav[j] == '-'){
                j++;
                lev++;
            }
            
            int val = 0;
            while(j < trav.size() && trav[j] != '-'){
                val = 10 * val + (trav[j] - '0');
                j++;
            }
            
            TreeNode* newnode = new TreeNode(val);
            while(s.size() > lev)s.pop();
            if(!s.empty()){
                if(s.top() -> left)s.top() -> right = newnode;
                else s.top() -> left = newnode;
            }
            s.push(newnode);
            i = j;
        }
        
        if(s.empty())return NULL;
        while(s.size() > 1)s.pop();
        return s.top();
    }
};