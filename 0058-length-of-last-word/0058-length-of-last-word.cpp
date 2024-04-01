class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n=s.size();
        int count=0;
        for(int i=n-1; i>=0; i--) {
            if(s[i]==' ' && !count)
            continue;

            if(s[i]!=' ')
            count++;

            else
            break;
        }

        return count;
    }
};