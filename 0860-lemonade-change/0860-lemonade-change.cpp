class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      int sum=0;
      int countfive=0;
      int countten=0;
        
      for(int i=0;i<bills.size();i++){
        if(bills[i]==5)countfive++;
          
        else if(bills[i]==10){
           if(countfive>0){countfive--; countten++;}
           else return 0;
        }
        else if(bills[i]==20){
            if(countfive>0 and countten>0){
                countfive--;
                countten--;
            }
            else if(countfive>=3)countfive-=3;
            else return 0;
        }
        cout<<countfive<<" "<<countten<<endl;
      } 
      return true; 
    }
};