class Solution {
public:
long long  ncr(int n,int r){
   long long ans=1;
    for(int i=0;i<r;i++)
    {
    ans=ans*(n-i);
    ans=ans/(i+1);
    }
    return ans;
}
    vector<int> getRow(int rowIndex) {
        vector<int>result;
        for(int c=0;c<=rowIndex;c++)
        {
            result.push_back(ncr(rowIndex,c));
        }

        return result;
    }
};