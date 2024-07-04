/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* k=head;ListNode* n=head;
        while(k!=NULL){
            if(k->val==0){
                int v=0;
                n=k->next;
                while(n!=NULL && n->val!=0)
                {
                    v+=n->val;
                    n=n->next;
                }
                k->val=v;
                if(n->next==NULL) k->next=NULL;
                else k->next=n;
            }
            k=k->next;
        }
        return head;
    }
};