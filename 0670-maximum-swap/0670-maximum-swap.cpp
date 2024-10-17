class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int maxi = -1;
        vector<int>copy(s.size(),0);
        for(int i=0;i<s.size();i++){
            copy[i]=s[i]-'0';
        }
        vector<int>nge(s.size(),-1);
        maxi=s.size()-1;
        for(int i=s.size()-2;i>=0;i--){
            if(copy[i]>copy[maxi]){
                maxi=i;
                nge[i]=-1;
            }
            else if(copy[i]==copy[maxi]){
                nge[i]=-1;
            }else{
                nge[i]=maxi;
            }
        }
        for(int i=0;i<nge.size();i++)
        {
            if(nge[i]!=-1){
                swap(copy[i],copy[nge[i]]);
                break;
            }
        }
        int ans = 0;
        int mult=1;
        for(int i=copy.size()-1;i>=0;i--){
            ans+=(copy[i]*mult);
            mult*=10;
        }
        return ans;
    }
};