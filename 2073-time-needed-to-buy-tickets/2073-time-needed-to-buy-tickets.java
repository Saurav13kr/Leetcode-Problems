class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int time = 0;
        int val = tickets[k];
        
        for(int i = 0; i <= k; i++){
            time += Math.min(tickets[i], val);
        }

        for(int i = k + 1; i < tickets.length; i++){
            time += Math.min(tickets[i], val - 1);
        }
        return time;
    }
}