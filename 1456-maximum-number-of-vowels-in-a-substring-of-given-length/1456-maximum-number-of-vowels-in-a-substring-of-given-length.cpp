class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        unordered_map<char,int> uno;
        string a=s.substr(0,k);

        for(auto i:a){
            if(i=='a' ||i=='e' || i=='i' || i=='o' || i=='u' ){
                uno[i]++;
            }
        }
        int count=0;

        for(auto i:uno){
            count += i.second;
        }

        int start=0;
        int end=k;
        int pre=count;

        while(end<n){
            int local=pre;
            a.erase(0,1);
            a += s[end];
            if(s[end]=='a' ||s[end]=='e' || s[end]=='i' || s[end]=='o' || s[end]=='u'){
               
                if(!(s[start]=='a' ||s[start]=='e' || s[start]=='i' || s[start]=='o' || s[start]=='u')){
                    local++;
                }
            }else{
                if((s[start]=='a' ||s[start]=='e' || s[start]=='i' || s[start]=='o' || s[start]=='u'))
                {
                    local--;
                }
            }
            
            pre=local;           
            count=max(local,count);
            start++;
            end++;
        }    
        return count;
    }
};
