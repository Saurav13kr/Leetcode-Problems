class Solution {
    public class pair{
        int temp;
        int idx;
        pair(int temp,int idx){
            this.temp=temp;
            this.idx=idx;
        }
    }
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<pair> st=new Stack<>();
        int n=temperatures.length;
        int[] res=new int[n];
        st.push(new pair(temperatures[n-1],n-1));
        int cnt=0;
        res[n-1]=0;
        for(int i=n-2;i>=0;i--){
           while(!st.isEmpty() && temperatures[i]>=st.peek().temp){
               st.pop();
           }
           if(st.isEmpty()){
               res[i]=0;
           }else{
               pair p=st.peek();
               int index=p.idx;
               res[i]=index-i;
           }
           st.push(new pair(temperatures[i],i));

        }
        return res;
    }
}