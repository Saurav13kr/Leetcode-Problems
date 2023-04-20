662. Maximum Width of Binary Tree
Given the root of a binary tree, return the maximum width of the given tree.<br>

The maximum width of a tree is the maximum width among all levels.<br>

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
<br>
It is guaranteed that the answer will in the range of a 32-bit signed integer.<br>

 

Example 1:<br>


Input: root = [1,3,2,5,3,null,9]<br>
Output: 4<br>
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).<br>
Example 2:<br>


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
