/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode dummyHead = new ListNode(0, list1);
        ListNode first = null, last = null;
        while (list1 != null) {
            if (a == 1) {
                first = list1;
            } else if (b == 0) {
                last = list1.next;
                break;
            }
            a--; b--; list1 = list1.next;
        }
        first.next = list2;
        while (first.next != null) {
            first = first.next;
        }
        first.next = last;
        return dummyHead.next;
    }
}