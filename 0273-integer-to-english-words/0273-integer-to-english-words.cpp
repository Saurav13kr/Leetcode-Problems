class Solution {
public:
    vector<std::string> counts={"Thousand","Million","Billion"};
    std::vector<std::string> ones = {" ","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    std::vector<std::string> tens = {" ","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    std::vector<std::string> teens = {"Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    string convertinttostring(int nums){
        string ans;
        bool lastspaceremove=true;
        cout<<nums<<" "<<nums/100<<" "<<endl;
        if(nums>=100) 
        {
            cout<<"1"<<endl;
            ans+=ones[nums/100]+" Hundred "; nums%=100;
        }
        if(nums>=20) 
        {
            cout<<"2"<<endl;
            ans+=tens[(nums/10)-1]+" ";
            nums%=10;
            
        }
        if(nums>=10 ) 
        {
            cout<<"3"<<endl;
            cout<<nums/10<<endl;
            nums%=10;
             ans+=teens[nums%10]+" ";
            
        }
        else if(nums>0) {
            cout<<"4"<<endl;
            ans+=ones[nums]+" ";
            nums%=10;
            
        }
        return ans;
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string ans="";
        int i=0;
        while(num>0){
            int j=1,no=0;
 
            int reverseno=num%1000;
            num/=1000;
            string tempstr="";
            tempstr=convertinttostring(reverseno);
            cout<<"ans "<<tempstr<<endl;
            if(i>0 && !tempstr.empty())
            {
                tempstr+=counts[i-1]+" ";
            }
            ans=tempstr+ans;
            i++;

        }
        size_t endpos = ans.find_last_not_of(" ");
        if (std::string::npos != endpos) {
            ans = ans.substr(0, endpos + 1);
        }

        
        return ans;
    }
};