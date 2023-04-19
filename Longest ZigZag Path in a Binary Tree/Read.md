1372. Longest ZigZag Path in a Binary Tree<br>
<br>
You are given the root of a binary tree.<br>
<br>
A ZigZag path for a binary tree is defined as follow:<br>
<br>
Choose any node in the binary tree and a direction (right or left).<br>
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.<br>
Change the direction from right to left or from left to right.<br>
Repeat the second and third steps until you can't move in the tree.<br>
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).<br>
<br>
Return the longest ZigZag path contained in that tree.<br> 
Example 1:<br>
<br>
<img src="![image](https://user-images.githubusercontent.com/124197263/233087128-475666b7-def0-48e0-bc96-de6b643339b0.png)">

<br>
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]<br>
Output: 3<br>
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).<br>
<br>
Example 2:<br>
<img src="![image](https://user-images.githubusercontent.com/124197263/233087288-8269807c-7b29-4059-a645-ce88923d429a.png)">
<br>

Input: root = [1,1,1,null,1,null,null,1,1,null,1]<br>
Output: 4<br>
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).<br>
<br>
Example 3:<br>
<br>
Input: root = [1]<br>
Output: 0<br>

Constraints:

The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100
