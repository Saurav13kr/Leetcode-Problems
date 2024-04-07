class Solution {
public:
    bool checkValidString(string s) 
    {
        int closing_max = 0;
        int closing_min = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '(')
            {
                closing_max++;
                closing_min++;
            }
            else if(s[i] == '*'){
                closing_max++;
                
                if(closing_min > 0) closing_min--;
            } else{
                if(closing_max == 0) return false;
                
                else if(closing_min == 0) closing_max--;
                else{
                    closing_max--;
                    closing_min--;
                }
            }
        }
        
        if(closing_min != 0) 
            return false;
        
        return true;
    }
};