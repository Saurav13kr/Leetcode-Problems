class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size(), count = 0;
        for(int i = 0;i<n;i++){
            if(count<=0)
                count=0;
            if(logs[i]=="../"){
                count--;
            }
            else if(logs[i]=="./"){

            } else{
                count++;
            }
        }
        if(count<=0)
            count=0;
        return count;
    }
};