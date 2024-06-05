
class Solution {
public:
    //Function to calculate length of LL
    int length(ListNode* head)
     {
         ListNode* temp = head;
         int l = 0;

         while(temp != NULL)
         {
             temp = temp->next;
             l++;
         }

         return l;
     }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
{
        ListNode* temp=head;
        int len = length(head);
        int cnt = 1;
        
        if(len==n) return head->next;  //If first node is to be removed
        
        while(cnt!=len-n){  //Take the temp ptr to the node to be removed 
            temp=temp->next;
            cnt++;
        }
        
        temp->next=temp->next->next;
        return head;
    }
};
