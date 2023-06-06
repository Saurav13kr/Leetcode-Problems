class StockSpanner {
public:
    stack<int> x;
    vector<int> z;
    int i=0;
    
    StockSpanner() {     
    }
    int next(int price) {
        z.push_back(price);
        int c;
        while(!x.empty() && price>=z[x.top()]) x.pop(); 
        c = x.empty() ? (i+1):(i-x.top());
        x.push(i++);
        
        return c;
    }
};