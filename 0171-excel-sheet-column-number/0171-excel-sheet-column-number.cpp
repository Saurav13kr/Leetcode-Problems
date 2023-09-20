class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        if(n==1){
            return columnTitle[0] - 'A' + 1;
        }
        
        int power = 0;
        int ans = 0;
        
        for(int i= n-1; i>=0; i--){
            int ch = columnTitle[i] - 'A' +1;
            ans += ch* pow(26, power);
            power++;
        }
        return ans;
    }
};