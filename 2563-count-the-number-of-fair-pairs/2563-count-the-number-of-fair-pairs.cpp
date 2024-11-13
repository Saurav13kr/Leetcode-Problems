class Solution {
public:
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        long long ans=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1,left=-1,right=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(arr[i]+arr[mid]>=lower)
                {
                    left=mid;
                    r=mid-1;
                }
                else
                l=mid+1;
            }
            l=i+1,r=n-1;
            while(l<=r)
            {
                 int mid=(l+r)/2;
                if(arr[i]+arr[mid]<=upper)
                {
                    right=mid;
                    l=mid+1;
                } else
                r=mid-1;
            }
            if(left!=-1&&right!=-1){
            ans+=(right-left+1);}
            
        }
        return ans;
    }
};