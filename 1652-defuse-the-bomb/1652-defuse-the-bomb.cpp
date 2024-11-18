class Solution {
public:
   int getsum(int start,vector<int>&code,int shift){
    int n=code.size();
    int sum=0;
    if(shift>0){
    for(int j=1;j<=shift;j++)
    {
        sum+=code[(start+j)%n];
    }
    }
    else if(shift<0){
        for(int j=1;j<=-shift;j++){
            sum+=code[(start-j+n)%n];
        }
    }
    return sum;
   }
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> res(n,0);
        if(k==0) return res;
        
        for(int i=0;i<n;i++){
           res[i]= getsum(i,code,k);
           
        }
        return res;
        
    }
};