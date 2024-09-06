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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);
        ListNode* newHead = dummy;

        ListNode* current = head;
        while (current != nullptr) 
        {
            // If the value is not in the numSet, add it to the new list
            if (numSet.find(current->val) == numSet.end()) 
            {
                newHead->next = new ListNode(current->val);
                newHead = newHead->next;
            }
            current = current->next;
        }

        // Return the new linked list (starting from dummy's next)
        return dummy->next;
    }
};