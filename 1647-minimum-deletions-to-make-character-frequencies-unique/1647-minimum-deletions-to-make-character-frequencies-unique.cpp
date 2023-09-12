class Solution {
public:
    int minDeletions(string s) {
        vector<int> ch(26,0);
        for(int i=0;i<s.size();i++)
        ch[s[i]-'a']++;
        sort(ch.begin(),ch.end());
        int i=0;
        
        while(ch[i]==0)
        i++;
        int ans=0;
        
        while(i<26){
            if(i>0&&ch[i]!=0&&ch[i]==ch[i-1]){
                ans+=1;
                ch[i]=ch[i]-1;
                swap(ch[i],ch[i-1]);
                i--;
            }else{
                i++;
            }
        }
        return ans;
    }
};