class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        int swaps=0;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
            mp[row[i]]=i;
        
        for(int i=0;i<n;i+=2){
            int first=row[i];
            int second;
            if(first%2==0)
                second=first+1;
            else
                second=first-1;
            int temp,temp2;
            
            if(second!=row[i+1]){
                swaps++;
                temp2=mp[second];
                temp=row[i+1];
                row[i+1]=second;
                second=temp;
                row[temp2]=second;
                mp[row[i+1]]=i+1;
                mp[second]=temp2;
            }
        }
        return swaps;
    }
};