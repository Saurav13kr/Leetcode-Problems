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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while(temp){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        
        while(!st.empty()){
            int value = st.top();
            st.pop();
            if(temp->val == value){
                temp = temp->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};