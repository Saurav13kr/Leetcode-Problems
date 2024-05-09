class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>max;

        long count=0,res=0;
        for(int h:happiness){
            max.push(h);
        }
        
        while(!max.empty() && k>0){
            int h=max.top();
            max.pop();
            res+=(h-count) >=0 ? (h-count) : 0;
            count++;
            k--;

        }
        return res;
    }
};