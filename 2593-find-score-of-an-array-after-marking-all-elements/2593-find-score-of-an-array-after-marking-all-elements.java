class Solution {
    public long findScore(int[] nums) {
        int l = nums.length;
        int[][] a = new int[l][2];
        for(int i = 0; i < l; i++) {
            a[i] = new int[]{nums[i], i};
        }
        Arrays.sort(a, (a1, a2) -> {
            if(a1[0] == a2[0]) {
                return a1[1] - a2[1];
            }
            return a1[0] - a2[0];
        });
        Set<Integer> markedInd = new HashSet<>();
        long ans = 0;
        for(int i = 0; i < l; i++) {
            if(markedInd.contains(a[i][1])) 
            {
                continue;
            }
            ans += a[i][0];
            markIndex(markedInd, a[i][1], l);
        }
        return ans;
    }
    void markIndex(Set<Integer> marked, int i, int l) {
        marked.add(i);
        if(i > 0)
            marked.add(i-1);
        if(i < l-1)
            marked.add(i+1);
    }
}