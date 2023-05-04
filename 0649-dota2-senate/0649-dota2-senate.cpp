class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;  
        int len=senate.length();
        for(int i=0;i<len;i++){
            if(senate[i]=='R'){
                r.push(i);
            } else{
                d.push(i);
            }
        } 
        
        while( !r.empty()  || !d.empty() ){  
            int rr=-1,dd=-1;  
            if( !r.empty() ){  
                rr=r.front();
            }
            
            if( !d.empty() ){
                dd=d.front();
            }
            if(rr==-1 || dd==-1){  
                return dd==-1?"Radiant":"Dire";
            }
            
            if(rr<dd){  
                d.pop();
                r.pop();
                r.push(len++);   
            }
            else{  
                r.pop();
                d.pop();
                d.push(len++); 
            }
        } 
        return "";                     
    }
};