/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    static int ans;
    static int freq[];

    static void helper(TreeNode root){
        if(root==null) return;
        if(root.left==null && root.right==null){
            freq[root.val]++;
            int odd = 0;
            for(int i=1; i<=9; i++){
                if(freq[i]%2!=0) odd++;
            }
            if(odd<=1) ans++;
            freq[root.val]--;
            return;
        }

        freq[root.val]++;
        helper(root.left);
        helper(root.right);
        // BackTracking
        freq[root.val]--;
    }
    public int pseudoPalindromicPaths (TreeNode root) {
        freq = new int[10];
        ans = 0;
        helper(root);
        return ans;
    }
}