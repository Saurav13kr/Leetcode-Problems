
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        vector<int> ll;
        
        while(temp!=NULL){
            ll.push_back(temp->val);
            temp=temp->next;
        }
        reverse(ll.begin()+left-1, ll.begin()+right);
        temp =head;
        
        for(int i=0;i<ll.size();i++)
        {
            temp->val = ll[i];
            temp=temp->next;
        }

        return head;
    }
};
