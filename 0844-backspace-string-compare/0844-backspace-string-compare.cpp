class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return afterEditor(s) == afterEditor(t);
    }
    
    string afterEditor(string str){
        string ans;
        
        for(auto ch : str) {
            if(ch != '#')
                ans.push_back(ch);
            
            else if(!ans.empty())
                ans.pop_back();
        }
        
        return ans;
    }
};