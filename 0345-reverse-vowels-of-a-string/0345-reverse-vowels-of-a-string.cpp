class Solution {
public:
    string reverseVowels(string s) {
        int a=0, b=s.size()-1;
        
        while (a<b) 
        {
            a=s.find_first_of("aeiouAEIOU", a);
            b=s.find_last_of("aeiouAEIOU", b);
            
            if (a<b) 
            {
                swap(s[a++], s[b--]);
            }
        }
        
        return s;
    }
};