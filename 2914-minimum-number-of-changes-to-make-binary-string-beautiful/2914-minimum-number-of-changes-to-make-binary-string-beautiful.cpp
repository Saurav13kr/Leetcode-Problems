class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        if(n==0)return 0;
        int start=0,count=0;

        while(start<n)
        {
            if((start!=n-1)&&(s[start]!=s[start+1])){
                count++;
            }
                start=start+2;
        }
return count;
    }
};