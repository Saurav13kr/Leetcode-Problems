class Solution { 
public:
    int coinChange(vector<int> &coins, int amount) {
        vector <int> prev(10001), now(10001);
        for(int am=0; am<=amount; am++)
            prev[am] = am%coins[0]==0 ? am/coins[0] : 1e9;
        
        for(int cur=1; cur<coins.size(); cur++) {
            for(int am=0; am<=amount; am++) {
                int doNotTakeCoin = 0 + prev[am];
                int takeCoin = INT_MAX;
                if(coins[cur] <= am) 
                    takeCoin = 1 + now[am-coins[cur]];
                now[am] = min(takeCoin, doNotTakeCoin);
            }
            prev = now;
        }
        return (prev[amount] >= 1e9) ? -1 : prev[amount];
    }
};