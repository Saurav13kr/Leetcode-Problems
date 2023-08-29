class Solution {
public:
    int bestClosingTime(string cus) {
        int n=cus.size(),c=0,curp,h=0;
        for(int i=0;i<n;i++){
            if(cus[i]=='Y')
                c++;
        }
        curp=c;
        for(int i=0;i<n;i++){
            if(cus[i]=='Y')
                c--;
            else
                c++;
            if(curp>c){
                curp=c;
                h=i+1;
            }
        }
        return h;
    }
};