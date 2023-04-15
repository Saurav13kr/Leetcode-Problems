2218. Maximum Value of K Coins From Piles
<br>
There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.<br>
In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.
Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.
<br>
Example 1:
<br>
<img src="https://user-images.githubusercontent.com/124197263/232201071-00aac22c-94cf-489d-92d5-dcb1312a2a0b.png">
<br>

Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.
<br>
Example 2:
<br>
Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
Output: 706
Explanation:
The maximum total can be obtained if we choose all coins from the last pile.
<br>
<br>
n == piles.length
1 <= n <= 1000
1 <= piles[i][j] <= 105
1 <= k <= sum(piles[i].length) <= 2000
