class Solution {
public:
    int integerBreak(int n) {
        switch(n){
            case 2: return 1;
            case 3: return 2;
            case 4: return 4;
            case 5: return 6;
            case 6: return 9;
            case 7: return 12;
            case 8: return 18;
            case 9: return 27;
            case 10: return 36;
        }
        int value = pow(3, n / 3);
        if (n % 3 == 1) value = value / 3 * 4;
        else if (n % 3 == 2) value = value * 2;
        return value;
    }
};