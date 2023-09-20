class Solution {
public:
    string ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string thousands[4] = {"", " Thousand", " Million", " Billion"};
    string number(int n) {
        if(n < 20){
            return ones[n];
        }
        if(n < 100){
            return tens[n/10] + number(n%10);
        }
        if(n<1000){
           return ones[n/100] + " Hundred" + number(n%100);
        }
        
        for (int i = 3; i >= 0; i--) {
            if (n >= pow(1000, i)) {
                return number(n / pow(1000, i)) + thousands[i] + number(n % (int)pow(1000, i));
            }
        }
        return "";
    }
    string numberToWords(int num){
        if(num == 0)    return "Zero";
        return number(num).substr(1);
    }
};