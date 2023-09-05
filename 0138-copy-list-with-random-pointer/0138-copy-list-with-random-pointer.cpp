/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* solve(Node* head, unordered_map<Node*,Node*> &umap) {
        if(head==NULL)
            return NULL;
        
        Node* curr=new Node(head->val);
        umap[head]=curr;
        curr->next=solve(head->next,umap);
        curr->random=umap[head->random];
        return curr;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> umap;
        umap[NULL]=NULL;
        return solve(head,umap);
    }
};