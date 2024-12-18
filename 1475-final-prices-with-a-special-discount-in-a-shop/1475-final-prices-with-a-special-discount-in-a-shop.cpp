class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> sk; 
        
        for (int i = 0; i < prices.size(); ++i) {
            while (!sk.empty() && prices[i] <= prices[sk.top()]) {
                prices[sk.top()] -= prices[i];
                sk.pop(); 
            }
            sk.push(i); 
        }
        
        return prices; // Return the final result
    }
};