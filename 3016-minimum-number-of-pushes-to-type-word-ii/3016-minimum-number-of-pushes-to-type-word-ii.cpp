class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26, 0);
        for(char c: word)
        { 
            freq[c-'a']++;
        }
        sort(freq.begin(), freq.end()); 

        int ck = 8, mul=1, cnt=0;
        for(int i=25; i>=0; i--)
        {
            if(ck==0){
                ck = 8;
                mul++;
            }
            cnt += freq[i]*mul;
            ck--;
        }
        return cnt;
    }
};