public class Solution {
    public int climbStairs(int n) {
        int prepre = 0, pre = 1;
        for (int i = 0; i < n; i ++) {
            int tmp = prepre + pre;
            prepre = pre;
            pre = tmp;
        }
        return pre;
    }//climb
}