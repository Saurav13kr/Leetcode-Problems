# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        matrix = [[-1] * n for _ in range(m)]
        left = 0
        right = n
        top = 0
        bottom = m
        dummy=ListNode(0,head)
        curr=dummy
        c=0
        while left < right and top < bottom:
            for i in range(left, right):
                if not curr.next:
                    break
                matrix[top][i] = curr.next.val
                curr=curr.next
            top += 1
            for j in range(top, bottom):
                if not curr.next:
                    break
                matrix[j][right - 1] = curr.next.val
                curr=curr.next
            right -= 1
            if not (left < right and top < bottom):
                break
            for k in range(right - 1, left - 1, -1):
                if not curr.next:
                    break
                matrix[bottom - 1][k] = curr.next.val
                curr=curr.next
            bottom -= 1
            for l in range(bottom - 1, top - 1, -1):
                if not curr.next:
                    break
                matrix[l][left] = curr.next.val
                curr=curr.next
            left += 1
        return matrix