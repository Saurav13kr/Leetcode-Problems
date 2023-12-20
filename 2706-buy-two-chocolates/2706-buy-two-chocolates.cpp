class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices), end(prices));
        
        int min_1 = prices[0], min_2 = prices[1];
        int total = min_1 + min_2;        
        return (total <= money) ? money - total : money;
    }
};