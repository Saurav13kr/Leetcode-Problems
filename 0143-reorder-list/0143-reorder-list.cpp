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
    int find(ListNode* head){
        int ans=0;
        while(head!=NULL){
            head=head->next;
            ans++;
        }

        return ans;

    }
    ListNode* solve(ListNode* head,int mid){
        ListNode* temp;
        while(mid--){
           
            if(mid==0){
                temp=head->next;
                head->next=NULL;
            }
             head=head->next;
        }

        return temp;
    }

    ListNode* rev(ListNode* mid){
        ListNode* curr=mid;
        ListNode* prev=NULL;
        ListNode* forw=mid->next;

        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }

        return prev;
    }
    void reorderList(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return;
        }
        int l=find(head);
        ListNode* mid=solve(head,l/2);
        ListNode* newhead=rev(mid);
        ListNode *tail;
        while(head && newhead){
            ListNode* temp=head->next;
            head->next=newhead;
            head=temp;
            ListNode* temp2=newhead->next;
            tail=newhead;
            newhead->next=temp;
            newhead=temp2;
        }
        if(newhead){
            tail->next=newhead;
        }
    }
};