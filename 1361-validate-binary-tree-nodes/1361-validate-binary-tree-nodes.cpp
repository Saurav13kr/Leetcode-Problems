class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int>mp;       
        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<n;i++){
            int node=i;
            int rc=rightChild[i];
            int lc=leftChild[i];
            if(mp.find(lc)!=mp.end() ||mp.find(rc)!=mp.end()){
                return false;
            }
            
            if(lc!=-1){
                adj[i].push_back(lc);
                mp[lc]=node;
            }
            if(rc!=-1){    
                adj[i].push_back(rc);
                mp[rc]=node;
            }
        }
        int root=-1;
        
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end()){
                if(root!=-1)
                    return false;
                root=i;
            }
        }
        
        if(root==-1)
            return false;
    
        queue<int>q;
        int count=0;    
        vector<bool>visited(n,false);
        q.push(root);
        count=1;
        visited[root]=true;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto i:adj[node]){
                if(visited[i]==true)        
                    return false;
                if(!visited[i]){
                    visited[i]=true;
                    count++;
                    q.push(i);
                }
            }
        }
        
        if(count==n)
            return true;
        return false;
    }
};