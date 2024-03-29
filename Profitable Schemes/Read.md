879. Profitable Schemes


There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:<br>

Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]<br>
Output: 2<br>
Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.<br>
In total, there are 2 schemes.<br>
Example 2:<br>

Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]<br>
Output: 7<br>
Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.<br>
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).<br>
 

Constraints:

1 <= n <= 100<br>
0 <= minProfit <= 100<br>
1 <= group.length <= 100<br>
1 <= group[i] <= 100<br>
profit.length == group.length<br>
0 <= profit[i] <= 100<br>
