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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        bool flag=false;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
               TreeNode* node = q.front(); q.pop();
               temp.push_back(node->val);
               if(node->left) q.push(node->left);
               if(node->right) q.push(node->right);
            }
               
            if(flag==false){
                if(temp.size()==1 and temp[0]%2==0) return false;              
                for(int i=1;i<temp.size();i++){
                    if(temp[i]%2==0 or temp[i-1]>=temp[i]) return false;               
                }              
            }  

            else if(flag==true){
                if(temp.size()==1 and temp[0]%2!=0) return false; 
                 for(int i=1;i<temp.size();i++){
                    if(temp[i]%2!=0 or temp[i-1]<=temp[i]) return false;
                }
               
            }  
            
            flag = !flag;
           
        }

        return true;          
        
    }
};