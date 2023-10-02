class Solution {
public:
    bool winnerOfGame(string clr) {
        int n=clr.size();
        if(n<=2) 
            return false;
        int a=0,b=0;
        
       for(int i=1;i<n-1;i++){
           if(clr[i-1]=='A'&& clr[i]=='A' && clr[i+1]=='A') a++;
           
    else if(clr[i-1]=='B'&& clr[i]=='B' && clr[i+1]=='B') b++;
       }
       return a>b;
    }
};