class Solution {
    public int maxFrequencyElements(int[] nums) {
        int []ans = new int[101];
        int maxf = 0;
        for(int i=0; i<nums.length; i++){
            ans[nums[i]]++;
        }
        for(int i=0; i<ans.length; i++){
            if(maxf<ans[i]){
                maxf = ans[i];
            }
        }
        int sum = 0;
        for(int i=0; i<ans.length; i++){
            if(maxf==ans[i]){
                sum +=ans[i];
            }
        }

        return sum;
    }
}