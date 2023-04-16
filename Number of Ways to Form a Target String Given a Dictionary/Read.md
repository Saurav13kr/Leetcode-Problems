1639. Number of Ways to Form a Target String Given a Dictionary<br>
You are given a list of strings of the same length words and a string target.<br>
<br>

Your task is to form target using the given words under the following rules:<br>
target should be formed from left to right.<br>
To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.<br>
Repeat the process until you form the string target.<br>
Notice that you can use multiple characters from the same string in words provided the conditions above are met.<br>
<br>
Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.<br>

<br> 
Example 1:<br>
<br>
Input: words = ["acca","bbbb","caca"], target = "aba"<br>
Output: 6<br>
Explanation: There are 6 ways to form target.<br>
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")<br>
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")<br>
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")<br>
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")<br>
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")<br>
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")<br>


<br>
Example 2:<br>
<br>
Input: words = ["abba","baab"], target = "bab"<br>
Output: 4<br>
Explanation: There are 4 ways to form target.<br>
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")<br>
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")<br>
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")<br>
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")<br>
 
<br>
Constraints:<br>
<br>
1 <= words.length <= 1000<br>
1 <= words[i].length <= 1000<br>
All strings in words have the same length.<br>
1 <= target.length <= 1000<br>
words[i] and target contain only lowercase English letters.<br>
