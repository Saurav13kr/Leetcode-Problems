319. Bulb Switcher<br>
There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.<br>

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.<br>

 
Example 1:<br>

Input: n = 3<br>
Output: 1<br>
Explanation: At first, the three bulbs are [off, off, off].<br>
After the first round, the three bulbs are [on, on, on].<br>
After the second round, the three bulbs are [on, off, on].<br>
After the third round, the three bulbs are [on, off, off].<br>
So you should return 1 because there is only one bulb is on.<br>
<br>
Example 2:<br>
<br>
Input: n = 0<br>
Output: 0<br>

Example 3:<br>

Input: n = 1<br>
Output: 1<br>
 
Constraints:<br>
0 <= n <= 109<br>
