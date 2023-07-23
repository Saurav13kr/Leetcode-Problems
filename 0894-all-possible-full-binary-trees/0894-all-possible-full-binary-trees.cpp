class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>> c;
        TreeNode* head=new TreeNode(0);
        c[1].push_back(head);

        for(int i=3;i<=n;i++){
            int m = i-1;
            int l=1;
            
            while(l<m){
                int r=m-l;
                if(c.count(l)>0&&c.count(r)>0){
                    auto lv = c[l];
                    auto rv = c[r];
                    
                    for(auto x:lv){
                        for(auto y:rv){
                            TreeNode* z=new TreeNode(0);
                            z->left=x;
                            z->right=y;
                            c[i].push_back(z);
                        }
                    }
                }
                l++;
            }
        }
        
        return c[n];
    }
};