
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        int rem=size%k;
        vector<ListNode*> ans;
        temp=head;
        
        while(temp!=NULL)
        {
            int count=size/k;
            ListNode* main=temp;
            ListNode* prev;
            while(count!=0)
            {
                prev=temp;
                temp=temp->next;
                count--;
            }
            if(rem)
            {
                prev=temp;
                temp=temp->next;
                rem--;
            }
            ans.push_back(main);
            prev->next=NULL;
        }
        while(ans.size()!=k)
        {
            ans.push_back(NULL);
        }
        return ans;
    }
};