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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        vector<int> ll;
        while(temp!=NULL){
            ll.push_back(temp->val);
            temp=temp->next;
        }
        reverse(ll.begin()+left-1, ll.begin()+right);
        temp =head;
        for(int i=0;i<ll.size();i++){
            temp->val = ll[i];
            temp=temp->next;
        }

        return head;
    }
};