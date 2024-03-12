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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head->next==0 && head->val==0) return NULL;
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* prevnode = new ListNode(0);
        prevnode->next = head;
        ListNode* prev = prevnode;
        ListNode* current = head;
        
        while (current != NULL) {
            int sum = 0;
            ListNode* temp = current;
            while (temp != NULL) {
                sum += temp->val;
                if (sum == 0) {
                    prev->next = temp->next;
                    current = temp->next;
                    break;
                }
                
                temp = temp->next;
            }
            if (sum != 0) {
                prev = current;
                current = current->next;
            }
        }

        return prevnode->next;
    }
};