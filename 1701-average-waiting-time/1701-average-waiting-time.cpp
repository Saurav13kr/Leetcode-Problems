class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int a = customers[0][0];
        double t = 0;
        for(const auto& c:customers){
            if(c[0]>a){
                a = c[0] + c[1];
            } else {
            a+=c[1];
            }
            
            t+=(a-c[0]);
        }
        
        return t/customers.size();
    }
};