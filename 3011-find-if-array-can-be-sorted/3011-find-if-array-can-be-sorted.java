class Solution {
    public boolean canSortArray(int[] nums) {
        int i,n=nums.length;
        ArrayList<ArrayList<Integer>> arr=new ArrayList<>();
        int prev_set_bits=0;

        int in=nums[0];
        while(in!=0){
            
            in=in&(in-1);
            prev_set_bits++;
        }

        ArrayList<Integer> sub=new ArrayList<>();
        for(i=0;i<n;i++){
            int num=nums[i],bits=0;
            while(num!=0){
                num=num&(num-1);
                bits++;
            }
            if(bits==prev_set_bits){
                sub.add(nums[i]);
            } else{
                prev_set_bits=bits;
                arr.add(new ArrayList<>(sub));
                sub.clear();
                sub.add(nums[i]);
            }
        }
        arr.add(new ArrayList<>(sub));
        
        for(ArrayList<Integer> a:arr){
            Collections.sort(a);
        }
        for(i=0;i<arr.size()-1;i++){
            if(arr.get(i).get(arr.get(i).size()-1)>arr.get(i+1).get(0))
            return false;
        }
        return true;
    }
}