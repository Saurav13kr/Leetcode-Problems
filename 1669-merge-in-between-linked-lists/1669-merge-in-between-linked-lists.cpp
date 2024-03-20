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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
	ListNode* res = new ListNode(-1, list1);
	ListNode* dummy = res;

	int cnt = 0;
	ListNode *first, *second;
	while (cnt <= b) {
		if (cnt == a)
			first = dummy;
		if (cnt == b)
			second = dummy->next;
		dummy = dummy->next;
		cnt++;
	}
	first->next = list2;
	while (list2->next)
		list2 = list2->next;
	list2->next = second->next;

	return res->next;
    }

};