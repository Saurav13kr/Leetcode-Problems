class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1 != NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* result = new ListNode();
        int carry = 0;
        int sum = 0;
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            result->val = sum % 10;
            carry = sum/10;
            ListNode* newNode = new ListNode(carry);
            newNode->next = result;
            result = newNode;
            sum = carry;
        }
        
        if(carry == 0){
            return result->next;
        }
        return result;
    }
};