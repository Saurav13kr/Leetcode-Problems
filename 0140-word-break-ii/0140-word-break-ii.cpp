class Solution {
public:
    vector<string>ans;
    
    struct trienode{
        char c;
        int z; 
        trienode *child[26];
        
        trienode(char c){
            z=0;
            this->c=c;
            for(int i=0;i<26;i++)child[i]=NULL;
        }
    };
    
    trienode *root; 
    void insertInTrie(string &word){
        trienode *cur=root;
        int idx;
        
        for(int i=0;i<word.size();i++){
            idx=word[i]-'a';
            if(!cur->child[idx]) 
            cur->child[idx]=new trienode(char(97+idx));
            cur=cur->child[idx];
        }
        cur->z+=1;
    }
    
    bool searchInTrie(string s){
        trienode *cur=root;
        int idx;
        for(int i=0;i<s.size();i++){
            idx=s[i]-'a';
            if(!cur->child[idx])return false; 
            cur=cur->child[idx] ;
        }
        return cur->z>0;
    }
    
    void solve(const string &s,string st,int pos){
        if(pos==s.size()){
            ans.push_back(st);
            return; 
        }
        st+=" ";
        for(int i=pos;i<s.size();i++){
            if(searchInTrie(s.substr(pos,i+1-pos)))
            solve(s,st+s.substr(pos,i+1-pos),i+1);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root=new trienode('/');
        
        for(auto it:wordDict){
            insertInTrie(it);  
        }
        
        for(int i=0;i<s.size();i++){
            if(searchInTrie(s.substr(0,i+1)))  
            solve(s,s.substr(0,i+1),i+1);
        }
        return ans;
    }
};