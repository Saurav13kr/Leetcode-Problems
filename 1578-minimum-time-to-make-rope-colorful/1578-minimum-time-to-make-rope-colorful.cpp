class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int m=0,j;
        for(int i=0;i<colors.size()-1;i++){ 
            j=0;
            if(colors[i]==colors[i+1])
            {
                j=i+2;
                int a=max(neededTime[i],neededTime[i+1]),b=neededTime[i]+neededTime[i+1]-a;
                while(j<colors.size()&&colors[i]==colors[j])
                {
                    if(a<neededTime[j])
                    {
                        b+=a;
                        a=neededTime[j];
                    }
                    else
                    b+=neededTime[j];
                    j++;
                }
                m+=b;
            }
            if(j>0)
            i=j-1;
        }
        return m;
    }
};