class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* prev = head, *curr = head -> next, *ans = head -> next;
        
        while(1) 
        {
            prev -> next = curr -> next;
            curr -> next = prev;
            ListNode* temp = prev -> next;
            if(temp == NULL)
                break;
            
            curr = temp -> next;
            if(curr == NULL)
                break;
            prev->next=curr;
            prev = temp;
        }
        
        return ans;
    }
};
