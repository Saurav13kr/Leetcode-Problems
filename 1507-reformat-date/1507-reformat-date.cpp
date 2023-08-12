class Solution {
    unordered_map<string, string> months={{"Jan", "01"}, 
                                          {"Feb", "02"}, 
                                          {"Mar", "03"}, 
                                          {"Apr", "04"}, 
                                          {"May", "05"}, 
                                          {"Jun", "06"}, 
                                          {"Jul", "07"}, 
                                          {"Aug", "08"}, 
                                          {"Sep", "09"}, 
                                          {"Oct", "10"}, 
                                          {"Nov", "11"}, 
                                          {"Dec", "12"}};
    
public:
    string reformatDate(string date) {
        stringstream ss(date);
        string d, m, y;
        ss>>d; ss>>m; ss>>y;

        m=months[m];
        d=to_string(stoi(d));
        if(d.size()==1)d="0"+d;
        
        return  y + "-" + m + "-" + d;
    }
};