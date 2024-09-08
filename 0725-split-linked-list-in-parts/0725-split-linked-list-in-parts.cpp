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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        ListNode* temp = head;
        int totalNodes = 0;

        while (temp != nullptr) {
            totalNodes++;
            temp = temp->next;
        }

        int partSize = totalNodes / k;
        int remainder = totalNodes % k;

        ListNode* current = head;

        for (int i = 0; i < k && current != nullptr; i++) {
            result[i] = current;
            int currentPartSize = partSize + (remainder > 0 ? 1 : 0);  
            remainder--;

            for (int j = 1; j < currentPartSize; j++) {
                current = current->next;
            }

            ListNode* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }

        return result;
    }
};