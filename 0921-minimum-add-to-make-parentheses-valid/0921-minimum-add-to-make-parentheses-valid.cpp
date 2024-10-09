class Solution {
public:
    int minAddToMakeValid(string s) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        
        int open = 0;

        int m = 0;
        for(char ch: s){
            if(ch == '('){
                open++;
            } else{
                open > 0 ? open-- : m++;
            }
        }

        return open + m;
    }
};