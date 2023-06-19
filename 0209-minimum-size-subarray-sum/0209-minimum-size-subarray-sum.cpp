class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int len=INT_MAX;

        int sumAll=0;
        int maxel=INT_MIN;
        for(int i=0;i<n;i++){
            sumAll+=nums[i] ;
            maxel=max(maxel,nums[i]);
        }
        if(maxel>=target){
            return 1;
        }
        if(sumAll<target){
            return 0;
        }
        if(sumAll==target){
            return n;
        }

        int sum=nums[0];
        int e=1;
        int l=2;
        for(int i=0;i<n;i++){
            if(i>0){
                sum-=nums[i-1];
            }
            int j=e;
            int length=l-1;
            while(sum<target && j<n){
                sum+=nums[j];
                j++;
                length++;
            }
            if(sum>=target){
                len=min(len,length);
                l=length;
                e=j;
                cout<<sum<<" for "<<i<<endl;
            }
        }
        return len;
    }
};