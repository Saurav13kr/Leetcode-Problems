class Solution {
public:
    int minFlips(int o, int m, int c) {
        int x=0;
        int n=32; 
        for(int i=0; i<32; i++){
            int l=(o>>i)&1, j=(m>>i)&1, k=(c>>i)&1;
            if(k==1){
                if(l==1 || j==1){}
                else{
                    x++;
                }
            } else{
                if(l==1 && j==1){
                    x+=2;
                }
                else if(l==1 || j==1){
                    x++;
                }
           }
        }
        return x;
    }
};