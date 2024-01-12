class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        // size of string
        int size = s.size();

        int countA = 0, countB = 0;

        // split point
        int point = size / 2;

        for(int i=0;i<size;i++) {
            if(i < point) {
                if(isVowel(s[i])) countA += 1;
            }
            else {
                if(isVowel(s[i])) countB += 1;
            }
        }

        return countA == countB;
    }
};