class Solution {
    public long continuousSubarrays(int[] nums) {
        long rc = 0;
        TreeMap<Integer,Integer> map = new TreeMap();
        int j = 0;
        int prev = 1;
        for (int i=0;i<nums.length;i++) {
            int val = nums[i];
            while ( j<i && (map.floorKey(val-3) != null || map.ceilingKey(val+3) != null ) ) {
                int v = nums[j++];
                map.put( v, map.get(v) - 1 );
                if ( map.get(v) == 0 )
                    map.remove(v);
                prev--;
            }
            map.put(val,map.getOrDefault(val,0)+1);
            rc+=prev++;
        }
        
        return rc;
    }
}